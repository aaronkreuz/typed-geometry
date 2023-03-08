import json
import os
import numpy as np

# NOTE: file containing shared functionalities

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


def get_object_dim_from_name(s :str):
    try:
        start_template = s.index("<")
        end_template = index_of_closing(s, start_template)
        s = s[start_template+1:end_template]
        l = s.split(',')
        l = [e.strip() for e in l]

        filtered_list = filter(lambda a: (a == "D" or a == "1" or a == "2" or a == "3" or a == "4"), l)

        l = list(filtered_list)
        if(len(l) >= 1):
            return l[0] # in case of no deviation of objectDim and domainDim this will just return the domainDim which is intended
        else:
            return ""
    except ValueError as ve:
        return ""


# returning string containing the template information for 'type' from type_file
def get_type_template(type, type_path: str):
    if (type[1]+'.hh') in os.listdir(type_path):
        in_file = type_path + type[1] +'.hh'
    else:
        in_file = type_path + "objects/" + type[1] + '.hh'

    text = open(in_file, "r").read()

    lines = text.split('\n')
    line_index = 0

    while line_index < len(lines):
        line_temp = lines[line_index]

        if line_temp.startswith('template'):
            line_next = lines[line_index+1]

            if type[0] in line_next:
                start_ind = line_next.index(type[0])
                if not (start_ind + len(type[0]) > (len(line_next) - 1)):
                    if not (line_next[start_ind + len(type[0])] != " " or line_next[start_ind + len(type[0])] != ";"):
                        # wrong type declaration -> continue searching
                        line_index += 1
                        continue    
                    

            # line containing template info about the type
            start_template = line_temp.index('<')
            end_template = index_of_closing(line_temp, start_template)

            return line_temp[start_template:end_template+1]

        line_index += 1
    
    # default case -> might not be matching
    return "<int D, class ScalarT>"


# NOTE: just beautifying and making the template names uniform to print into object function file
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


def template_format_values(s: str):
    t = s
    t = t[1:len(s)-1]
    arguments = []
    # TODO: not sure if required here
    while "<" in t:
        start = t.index("<")
        end = index_of_closing(t, start)
        t = t[:start] + t[end+1:]

    t_list = t.split(",") # containing the arguments

    output = "<"

    for arg in t_list:
        arg = arg.strip() # remove leading whitespaces
        while " " in arg:
            start = arg.index(" ")
            arg = arg[start+1:]
            output += arg + ", "

    output = output[:-2]
    output += ">"

    return output


# NOTE: parse relevant information of the given function and store info in dictionary (unary function case)
def parse_function_info_unary(func, function_name: str, type: str):
    
    if not (func['function_declaration']['name'].startswith(function_name)):
        return {}

    func_decl_params = func['function_declaration']['parameters']

    # check if function params contain type (requirement)
    param_name =  func_decl_params[0]['type_name']
    if ('<' in param_name):
        param_name = param_name[:param_name.index('<')]

    if not param_name == type:
        return {} # types not matching

    # build object for specific function implementation
    function = {} #empty object
    function["function_name"] = func['function_declaration']['name']
    function["domain_dim"] = func_decl_params[0]['domain_dim']
    function["object_dim"] = func_decl_params[0]['object_dim']
    function["return_type"] = func['function_declaration']['return_type']

    return function


# NOTE: parse relevant information of the given function and store info in dictionary (binary sym. function case)
def parse_function_info_binary_symmetric(func, function_name: str, type_a: str, type_b: str):
    if(func['function_declaration']['name'].startswith(function_name)):
            func_decl_params = func['function_declaration']['parameters']
            symmetric = False # true if function implemented via symmetric case

            if(len(func_decl_params) != 2): # ensure 2 parameters
                return {}

            type_name_a = func_decl_params[0]['type_name']
            type_name_b = func_decl_params[1]['type_name']
            if ("<" in type_name_a):
                type_name_a = type_name_a[:type_name_a.index("<")]
            if("<" in type_name_b):
                type_name_b = type_name_b[:type_name_b.index("<")]

            # TODO: Maybe no longer required
            if not (func_decl_params[0]['type_name'].startswith(type_a) and func_decl_params[1]['type_name'].startswith(type_b)):
                return {}

            # check if types are matching
            if not (type_name_a == type_a and type_name_b == type_b):
                if (type_name_b == type_a and type_name_a == type_b):
                    symmetric = True # sysmmetric case (swap implementation later)
                else:
                    return {}

            if not (func_decl_params[0]['domain_dim'] == func_decl_params[1]['domain_dim']): # should not appear
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
            function["symmetric"] = symmetric
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


# NOTE: return the index of the given list where the objec dim of the second parameter type is matching 'dim'
def contains_object_dim(separated_funcs, dim: int):
    count = 0
    for f_list in separated_funcs:
        if f_list[0]['params'][1]['object_dim'] == dim:
            return count
        count += 1
    return -1


# NOTE: separate the given function into sub-lists based on the object-domain of the 2nd type (binary symmetric case)
def separate_funcs(funcs):
    separated_funcs = [] # list containing the domain-classes regarding type b
    for f in funcs:
        object_dim_b = f['params'][1]['object_dim']
        assert (object_dim_b != "")
        ind = contains_object_dim(separated_funcs, object_dim_b)
        if ind != -1: # object dim already in 'separated_funcs' at index 'ind'
            separated_funcs[ind].append(f)
        else: # object dim not seen before -> append to list
            separated_funcs.append([f])

    return separated_funcs
        

# NOTE: sorting the function list 'functions_parsed' according to the dimensionalities of the parameters distinguishing between cases where types depend on the object dimensions
def sorting_funcs(functions_parsed, a_obj_dim: bool, b_obj_dim: bool):
    if(a_obj_dim and b_obj_dim):
        functions_parsed.sort(key = lambda f : tuple((f['params'][1]['object_dim'], f['params'][0]['domain_dim'], f['params'][0]['object_dim']))) # sort according to dim in ascending order
        return

    if(a_obj_dim): # implicitly 'and not b_obj_dim'
        functions_parsed.sort(key = lambda f : tuple((f['params'][0]['domain_dim'], f['params'][0]['object_dim']))) # sort according to dim in ascending order
        return

    if(b_obj_dim): # implicitly 'and not a_obj_dim'
        functions_parsed.sort(key = lambda f : tuple((f['params'][1]['object_dim'], f['params'][0]['domain_dim']))) # sort according to dim in ascending order
        return
    
    else: # not a_obj_dim and not b_obj_dim
        functions_parsed.sort(key = lambda f : (f['params'][0]['domain_dim'])) # sort according to dim in ascending order
        return


# NOTE: write unary function to file for type with varying domain dim and object dim
def write_unary_domain_object_d(gen: code_generator, funcs, type: str, template: str):
    found_dom_d = False
    found_obj_d = [False] # per entry info if arbitrary object dim has been found for i-th domain dim (keeping track via 'dom_d_it')
    curr_dom_d = funcs[0]["domain_dim"]
    dom_d_it = 0 # keeping track of current nbr of different domain dims seen
    func_counter = 0 # tracking number of functions written to the file

    # iterating over parsed functions
    for f in funcs:
        dom_d = f['domain_dim']
        obj_d = f['object_dim']

        if dom_d != curr_dom_d:
            curr_dom_d = dom_d
            found_obj_d.append(False)
            dom_d_it += 1

        # case 1: domain dim is not arbitrary (object dim may be arbitrary or not arbitrary)
        if dom_d != 'D':
            object_dim_appendix = ""
            if dom_d != 'O' and not found_obj_d[dom_d_it]:
                object_dim_appendix = "and O == {}".format(obj_d)
            else:
                 # found object dim 'O' for current domain dim -> no object dim. distinctions for curr domain dim from here
                found_obj_d[dom_d_it] = True

            gen.append_line("if constexpr(D == {dom_d} {obj_d_appendix})".format(dom_d = dom_d, obj_d_appendix = object_dim_appendix))
            begin_scope(gen)
            gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))
            end_scope(gen)
            func_counter += 1
            continue
        
        # case 2: domain dim is arbitrary and object dim is not arbitrary
        if dom_d == 'D' and obj_d != 'O':
            if found_obj_d[dom_d_it]:
                continue
            found_dom_d = True

            gen.append_line("if constexpr(O == {obj_d})".format(obj_d = obj_d))
            begin_scope(gen)
            gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))
            end_scope(gen)
            func_counter += 1
            continue

        # case 3: domain dim arbitrary and object dim equal to domain dim
        if(dom_d == 'D' and obj_d == 'D'):
            if found_dom_d and found_obj_d[dom_d_it]:
                continue # case already handled
            found_dom_d = True
            found_obj_d[dom_d_it] = True

            gen.append_line("if constexpr(D == 0)")
            begin_scope(gen)
            gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))
            end_scope(gen)
            func_counter += 1
            continue

        # case 4: domain dim and object dim arbitrary
        if dom_d == 'D' and obj_d == 'O':
            # if found_dom_d and all(found_obj_d):
            #     continue # case already handled

            found_dom_d = True
            found_obj_d = [True for elem in found_obj_d]

            if(func_counter > 0): # else appropriate
                gen.append_line("else")
                begin_scope(gen)
                gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))
                end_scope(gen)

            else:
                gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))

            func_counter += 1
            break #all cases handled

    if not (found_dom_d and all(found_obj_d)):
        # not all domain dim and object dim configurations are handled by the given functions
        if func_counter == 0:
             gen.append_line('static_assert(cc::always_false<{type}{templ}>, "TODO: not yet implemented");'.format(type=type, templ = template))
        else:
            gen.append_line("else")
            begin_scope(gen)
            gen.append_line('static_assert(cc::always_false<{type}{templ}>, "TODO: not yet implemented");'.format(type=type, templ = template))
            end_scope(gen)

    return 


# NOTE: writing unary function to file for type only depending on the domain dim (i.e. always domain_dim == object_dim)
def write_unary_domain_d(gen: code_generator, funcs, type: str, template: str):
    found_dom_d = False
    func_counter = 0

    # iterating over parsed functions
    for f in funcs:
        dom_d = f["domain_dim"]

        # case 1: domain dim is not arbitrary
        if dom_d != 'D' and not found_dom_d:
            gen.append_line("if constexpr(D == {dom_d})".format(dom_d = dom_d))
            begin_scope(gen)
            gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))
            end_scope(gen)
            func_counter += 1
            continue
        
        # case 2: domain dim is abitrary
        if dom_d == 'D' and not found_dom_d:
            found_dom_d = True
            if func_counter > 0:
                gen.append_line("else")
                begin_scope(gen)
                gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))
                end_scope(gen)
            else:
                gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))
            func_counter += 1
            break

    if not found_dom_d:
        # not all domain_dim cases are handled by the given functions
        if func_counter == 0:
            gen.append_line('static_assert(cc::always_false<{type}{templ}>, "TODO: not yet implemented");'.format(type = type, templ = template))
        else:
            gen.append_line("else")
            begin_scope(gen)
            gen.append_line('static_assert(cc::always_false<{type}{templ}>, "TODO: not yet implemented");'.format(type=type, templ = template))
            end_scope(gen)

    return


# NOTE: Cases depending on DomainDimension AND ObjectDimension, but only type_a! If type_b also has deviating objectDim, overloading is required
def write_bin_symmetric_TypeAObjectD(gen: code_generator, funcs, type_a: str, type_b: str, template_a: str, template_b: str):
    found_dom_d = False
    found_obj_d = [False]
    curr_dom_d = funcs[0]['params'][0]["domain_dim"]
    dom_d_it = 0 # keeping track of current nbr of different domain dims seen
    func_counter = 0 # tracking number of functions written to the file

    for f in funcs:
        # dims of the types for given function f
        dom_D_a = f['params'][0]["domain_dim"]
        object_D = f['params'][0]["object_dim"]
        dom_D_b = f['params'][1]["domain_dim"]
        symmetric_impl = f['symmetric']

        assert(dom_D_a == dom_D_b) # domain dims have to be the same

        dom_D = dom_D_a # dom is the same -> just take one for convenience

        if(dom_D != curr_dom_d): # new domain dim
            curr_dom_d = dom_D
            found_obj_d.append(False)
            dom_d_it += 1

        # case 1: objectDim arbitrary and domainDim not D
        if dom_D != 'D':
            object_dim_appendix = ""
            if object_D != 'O' and not found_obj_d[dom_d_it]:
                object_dim_appendix = "&& O == {}".format(object_D)
            else:
                # found object dim 'O' for current domain dim -> no object dim. distinctions for curr domain dim from here
                found_obj_d[dom_d_it] = True
                
            gen.append_line("if constexpr(D == {dom_dim} {object_dim})".format(dom_dim = dom_D, object_dim = object_dim_appendix))
            begin_scope(gen)
            gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
            end_scope(gen)

            func_counter += 1
            continue

        # Case 2: domainDim D and objectDim not O
        if dom_D == 'D' and object_D != 'O':
            found_dom_d = True
            gen.append_line("if constexpr(O == {object_dim})".format(object_dim = object_D))
            begin_scope(gen)
            gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
            end_scope(gen)

            func_counter += 1
            continue

        # Case 3 objectDim D and domainDim D (objectDim = domainDim)
        if dom_D == 'D' and object_D == 'D':
            if not found_dom_d or not found_obj_d:
                found_dom_d = True
                found_obj_d[dom_d_it] = True

                gen.append_line("if constexpr(D == O)")
                begin_scope(gen)
                gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
                end_scope(gen)

                func_counter += 1                    
                continue
        
        # case 4: domainDim D and objectDim O
        if dom_D == 'D' and object_D == 'O':
            # if found_dom_d and all(found_obj_D): # all cases already handled
            #     continue 
            found_dom_d = True
            found_obj_d = [True for elem in found_obj_d]

            if(func_counter > 0): # else appropriate
                gen.append_line("else")
                begin_scope(gen)
                gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
                end_scope(gen)

            else:
                gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))

            func_counter += 1
            break # all cases handled

    if not (found_dom_d and all(found_obj_d)):
        if func_counter > 0:
            gen.append_line("else")
            begin_scope(gen)
            gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a,templ_a = template_a, type_b=type_b, templ_b = template_b))
            end_scope(gen)
        else:
            gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a,templ_a = template_a, type_b=type_b, templ_b = template_b))
    
    return

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
                    end_scope(gen)
                    # TODO: HERE TO RETURN? -> Reached else-case
                    break

                if(func_counter == 0):
                    gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
        it += 1

    if not found_D:
        if func_counter == 0: # not found any function
            gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a,templ_a = template_a, type_b=type_b, templ_b = template_b))

        else: # found some (one) function before -> else does make sense
            gen.append_line("else")
            begin_scope(gen)
            gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a,templ_a = template_a, type_b=type_b, templ_b = template_b))
            end_scope(gen)

    return
