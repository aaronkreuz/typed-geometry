import json
import os
import numpy as np

# containing file information
class code_generator:
    def __init__(self) -> None:
        self.string = ""
        self.current_indent = 0

    def __str__(self) -> str:
        return self.string

    def indent(self, spaces=4) -> None:
        self.current_indent += spaces

    def unindent(self, spaces=4)-> None:
        self.current_indent -= spaces

    def append_line(self, s : str)-> None:
        self.string += " "*self.current_indent + s + "\n"

    def newline(self) -> None:
        self.append_line("")


#NOTE: little helpers
def end_scope(gen: code_generator):
    gen.unindent()
    gen.append_line("}")

def begin_scope(gen: code_generator):
    gen.append_line("{")
    gen.indent()

def index_of_closing(text: str, start: int) -> int:
    opening = text[start]
    assert opening == "{" or opening == "(" or opening == "<"
    closing = "}" if opening == "{" else ")" if opening == "(" else ">"
    count = 1
    for i in range(start + 1, len(text)):
        if text[i] == opening:
            count += 1
        elif text[i] == closing:
            count -= 1

        if count == 0:
            return i
    return -1


def get_dim_from_name(func_name: str) -> str:
    #last letter contains domain information
    str_len = len(func_name)
    last_letter = func_name[str_len-1]
    if(last_letter == '4'):
        return "4"
    if(last_letter == '3'):
        return "3"
    if(last_letter == '2'):
        return "2"
    if(last_letter == '1'):
        return "1"
    else:
        return "D"

# returning string containing the template information for 'type'
def get_type_template(type: str, type_path: str):
    if (type+'.hh') in os.listdir(type_path):
        in_file = type_path + type +'.hh'

    else:
        in_file = type_path + "objects/" + type + '.hh'

    text = open(in_file, "r").read()

    lines = text.split('\n')
    line_index = 0

    while line_index < len(lines):
        line_temp = lines[line_index]

        if line_temp.startswith('template'):
            # line containing template info about the type
            start_template = line_temp.index('<')
            end_template = index_of_closing(line_temp, start_template)

            return line_temp[start_template:end_template+1]

        line_index += 1
    
    return "<int D, class ScalarT>"


# NOTE: just beautifying and making the template names uniform
def adapt_template_format(s : str):
    # cut of traits
    if("class TraitsT" in s):
        ind = s.index("class TraitsT")
        s = s[:(ind-2)] + ">"

    if("int DomainD" in s):
        ind_start = s.index("int DomainD")
        ind_end = -1
        try:
            ind_end = s[ind_start:].index(",")
        except ValueError as ve:
            ind_end = s.index(">")

        s = s[:ind_start] + "int D" + s[ind_end:]

    if("int ObjectD" in s):
        ind = s.index("int ObjectD")
        rest = s[ind + len("int ObjectD"):]
        s = s[:ind] + "int O" + rest

    return s


# NOTE: parse relevant information of the given function and store info in dictionary
def parse_function_info_binary_symmetric(func, function_name: str, type_a: str, type_b: str):
    if(func['function_declaration']['name'].startswith(function_name)):
            func_decl_params = func['function_declaration']['parameters']

            type_name_a = func_decl_params[0]['type_name']
            type_name_b = func_decl_params[1]['type_name']
            if ("<" in type_name_a):
                type_name_a = type_name_a[:type_name_a.index("<")]
            if("<" in type_name_b):
                type_name_b = type_name_b[:type_name_b.index("<")]

            # TODO: Maybe no longer required
            if not (func_decl_params[0]['type_name'].startswith(type_a) and func_decl_params[1]['type_name'].startswith(type_b)):
                return {}

            if not (type_name_a == type_a and type_name_b == type_b):
                return {}

            if not (func_decl_params[0]['domain_dim'] == func_decl_params[1]['domain_dim']):
                return {}

            func_name_parsed = func['function_declaration']['name']

            domain_dim_a = func_decl_params[0]['domain_dim']
            object_dim_a = func_decl_params[0]['object_dim']
            domain_dim_b = func_decl_params[1]['domain_dim']
            object_dim_b = func_decl_params[1]['object_dim']

            # build object for specific function implementation
            function = {} #empty object
            function["function_name"] = func_name_parsed

            param_a = {}
            param_a["object_dim"] = object_dim_a
            param_a["domain_dim"] = domain_dim_a

            param_b = {}
            param_b["object_dim"] = object_dim_b
            param_b["domain_dim"] = domain_dim_b

            function["params"] = [param_a, param_b]
            # function["object_dim"] = object_dim
            # function["domain_dim"] = domain_dim
            function["return_type"] = func['function_declaration']['return_type']
            function["func_decl_params"] = func_decl_params # TODO: Maybe do not need to write out all param info

            return function


# NOTE: get the correct return type of a function
def get_return_type(functions_parsed) -> str:
    return_type_list = []
    if(len(functions_parsed) > 0):
        return_type_list = np.array(list(functions_parsed[0]['return_type']))
        # check if return type contains dimensional information:
        if '<' in return_type_list:
            inds = np.where(return_type_list == '<')
            for i in inds[0]:
                if return_type_list[i+1] == 'D' or return_type_list[i+1] == '1' or return_type_list[i+1] == '2' or return_type_list[i+1] == '3' or return_type_list[i+1] == '4':
                    return_type_list[i+1] = 'D' # make the return type in every case depending on D
    else:
        return_type_list = np.array(['a','u','t','o'])

    return_type = return_type_list.tolist()
    return_type = "".join(return_type)

    return return_type


# NOTE: Cases depending on DomainDimension AND ObjectDimension, but only type_a! If type_b also has deviating objectDim, overloading is required
def write_bin_symmetric_TypeAObjectD(gen: code_generator, funcs, type_a: str, type_b: str, template_a: str, template_b: str):
    found_dom_D = False
    found_obj_D = False
    func_counter = 0 # counting number of cases written to file
    it = 0 # counting the number of iterations done

    for f in funcs:
        # dims of the types for given function f
        dom_D_a = f['params'][0]["domain_dim"]
        object_D = f['params'][0]["object_dim"]
        dom_D_b = f['params'][1]["domain_dim"]

        assert(dom_D_a == dom_D_b) # domain dims have to be the same

        dom_D = dom_D_a # dom is the same -> just take one for convenience

        # objectDim and domainDim not D
        if dom_D != 'D':
            object_dim_appendix = ""
            if object_D != 'D':
                object_dim_appendix = "&& O == {}".format(object_D)

            gen.append_line("if constexpr(D == {dom_dim} {object_dim})".format(dom_dim = f['domain_dim'], object_dim = object_dim_appendix))
            begin_scope(gen)
            gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
            end_scope(gen)
            it += 1
            func_counter += 1
            continue

        # domainDim is D and objectDim not D
        if dom_D == 'D' and object_D != 'D':
            found_dom_D = True
            gen.append_line("if constexpr(O == {object_dim})".format(object_dim = object_D))
            begin_scope(gen)
            gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
            end_scope(gen)
            it += 1
            func_counter += 1
            continue

        # objectDim and domainDim are D
        if dom_D == 'D' and object_D == 'D':
            if not found_dom_D or not found_obj_D:
                found_dom_D = True
                found_obj_D = True

                if func_counter > 0: # found some funcs before -> else appropriate
                    gen.append_line("else")
                    begin_scope(gen)
                    gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
                    end_scope(gen)

                else: # no funcs found before
                    gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
                    
                it += 1
                break

    if not found_dom_D or not found_obj_D :
        if func_counter > 0:
            gen.append_line("else")
            begin_scope(gen)
            gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a,templ_a = template_a, type_b=type_b, templ_b = template_b))
            end_scope(gen)
        else:
            gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a,templ_a = template_a, type_b=type_b, templ_b = template_b))

    end_scope(gen) # end of function


# NOTE: Cases only depending on DomainDimension, simpler case. Input funcs sorted in ascending order regarding domain.
def write_bin_symmetric_DomainD(gen: code_generator, funcs, type_a: str, type_b: str, template_a: str, template_b: str):
    found_D = False # yet not found templated domain function
    func_counter = 0 # counting number of cases written to file
    it = 0 # counting the number of iterations done

    # iterating over func
    for f in funcs:
        dom = f['params'][0]['domain_dim']

        if(dom != 'D'): # D not yet found -> specific case delimited by the domain dim
            gen.append_line("if constexpr(D == {})".format(dom))
            begin_scope(gen)
            gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
            end_scope(gen)
            func_counter += 1

        else: # dom == D
            if not found_D: # dom D not reached before
                found_D = True
                if(func_counter > 0):
                    gen.append_line("else")
                    begin_scope(gen)
                    gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
                    end_scope
                    # TODO: HERE TO RETURN? -> Reached else-case
                    break

                if(func_counter == 0):
                    gen.append_line("return {function_name}(obj_a, oj_b);".format(function_name = f['function_name']))

        it += 1

    if not found_D:
        if func_counter == 0: # not found any function
            gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a,templ_a = template_a, type_b=type_b, templ_b = template_b))

        else: # found some (one) function before -> else does make sense
            gen.append_line("else")
            begin_scope(gen)
            gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a,templ_a = template_a, type_b=type_b, templ_b = template_b))
            end_scope(gen)

    end_scope(gen) # end of function
    return
