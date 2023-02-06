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

            domain_dim = func_decl_params[0]['domain_dim']
            object_dim = func_decl_params[0]['object_dim']

            # build object for specific function implementation
            function = {} #empty object
            function["function_name"] = func_name_parsed
            function["object_dim"] = object_dim
            function["domain_dim"] = domain_dim
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


# NOTE: Cases depending on DomainDimension AND ObjectDimension
# TODO: Tidy up and Debug!
def write_bin_symmetric_TypeAObjectD(gen: code_generator, funcs, type_a: str, type_b: str, template_a: str, template_b: str):
    found_dom_D = False
    found_obj_D = False
    for f in funcs:
        # objectDim and domainDim not D
        if f['domain_dim'] != 'D':
            object_dim_if = ""
            if(True):
                if(f['object_dim'] != 'D'): # This case might never occur
                    object_dim_if = "&& O == {}".format(f['object_dim'])
            gen.append_line("if constexpr(D == {dom_dim} {object_dim})".format(dom_dim = f['domain_dim'], object_dim = object_dim_if))
            gen.append_line("{")
            gen.indent()
            gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
            gen.unindent()
            gen.append_line("}")

        # TODO: Maybe case missing where only one of objectDim and domainDim are D

        # objectDim and domainDim are D    
        else:
            if not found_dom_D and not found_obj_D: # dimension D
                found_dom_D = True
                found_obj_D = True
                # no further ifs required here
                if len(funcs) > 1:
                    gen.append_line("else{")
                    gen.indent()
                    gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
                    gen.unindent()
                    gen.append_line("}")
                    # TODO: break?
                else:
                    gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))
                    # TODO: break?
    if not found_dom_D:
        if len(funcs) >= 1:
            gen.append_line("else{")
            gen.indent()
            gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a,templ_a = template_a, type_b=type_b, templ_b = template_b))
            gen.unindent()
            gen.append_line("}")
        # else:
                #should not happen -> catched in early-out
    gen.unindent()
    gen.append_line("}")


# NOTE: Cases only depending on DomainDimension, simpler case
# TODO: write function
def write_bin_symmetric_DomainD(gen: code_generator, funcs):
    return