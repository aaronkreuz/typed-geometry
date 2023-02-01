import os
import json
import numpy as np

# TODO: separate object_functions + object_function_uncommon

type_path = "../src/typed-geometry/types/"

common_types = [
    "aabb",
    "pos",
    "ray",
    "line",
    "segment",
    "sphere",
    "triangle",
    "plane"
]

advanced_types = [
    "aabb_boundary",
    "box",
    "box_boundary"
    "capsule", # currently only 3d
    "capsule_boundary",# currently only 3d
    "cone",
    "cone_boundary",
    "cone_boundary_no_caps",
    "cylinder",
    "cylinder_boundary",
    "cylinder_boundary_no_caps",
    "ellipse",
    "ellipse_boundary",
    "frustum", # currently only 3d
    "halfspace",
    "hemisphere",
    "hemisphere_boundary",
    "hemisphere_boundary_no_caps",
    "inf_cone",
    "inf_cone_boundary",
    "inf_cylinder",
    "inf_cylinder_boundary",
    "inf_frustum", # currently only 3d
    # "polygon", # not yet implemented
    # "polyline", # not yet implemented
    # "pyramid", # difficult due to varying base
    "quad", # difficult, because currently no guarantee that planar
    "sphere_boundary",
    "disk",
    "disk_boundary",
    # "circle", # same as disc_boundary
    # "tube", # same as cylinder_boundary_no_caps
    # "inf_tube", # same as inf_cylinder_boundary
    ] 

# todo: <type>2in3

all_types = common_types + advanced_types

print("Total types: {}".format(len(all_types)))

unary_functions = [
    #[func_name, file_name]
    ["edges_of", "edges"],  
    ["faces_of", "faces"],
    ["vertices_of", "vertices"],
    ["volume_of", "volume"],
    ["area_of", "area"],
    ["boundary_of", "boundary"],
    ["rasterize", "rasterize"],
    ["triangulate", "triangulate"],
    ["triangulation", "triangulation"],
    ["centroid_of", "centroid"],
    ["aabb_of", "aabb"],
    ["any_point", "any_point"],
    #["signed_distance", "signed_distance"]
]

binary_symmetric_functions = [
    ["intersects", "intersection"]
    #"intersection",  # representation problem
    # "closest_points",
    # "distance",
    # "distance_sqr"
]

binary_asymmetric_functions = [
    #["project", "project"],
    # "intersection_parameter",
    # "intersection_parameters",
    # "contains"  # potentially impl difficulty
]

tg_src_root = "" # todo
default_object_functions_path ="typed-geometry/object_functions.hh" # todo
object_functions_dir = "typed-geometry/object-functions/"

if not os.path.exists(object_functions_dir):
    os.makedirs(object_functions_dir)

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


# Generate template default
default_object_functions = \
"""#pragma once

#include <clean-core/always_false.hh>

template <class T>
struct object_functions
{
    static_assert(cc::always_false<T>
    , \"include missing\");
};"""

#with open(default_object_functions_path, "w") as f:
#    f.write(default_object_functions)

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


def get_dim_from_name(func_name: str):
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


def generate_function_unary(gen : code_generator, function_name : str, type: str, deserial_file):
    # 1st iterate through file and write functions into list incl. name and dimension
    # 2nd sort list according to dimension
    # 3rd write function to object file according to schema (see notes)

    # TODO: This only works if there is just one kind of unary function in the file. To expand to arbitray amount of functions:
    #       If encountering a founction name that is not yet stored in a list, create new list (i.e. list of lists)
    #       -> look for right list when encountering an function.
    #       Then build up the object file accoriding to schema for each outermost list.
    
    found_func = False

    # 1st iteration - pre pass
    functions_parsed = [] # empty list
    for i in deserial_file:
        if(i['function_declaration']['name'].startswith(function_name)):
            func_decl_params = i['function_declaration']['parameters']

            # check if function params contain type (requirement)
            if not any(d['type_name'].startswith(type) for d in func_decl_params):
                continue
            func_name_parsed = i['function_declaration']['name']
            dim = get_dim_from_name(func_name_parsed)

            # build object for specific function implementation
            function = {} #empty object
            function["function_name"] = func_name_parsed
            function["dim"] = dim
            function["return_type"] = i['function_declaration']['return_type']
            functions_parsed.append(function)

    # Extract the return type -> in-between pass
    return_type_list = []
    if(len(functions_parsed) > 0):
        return_type_list = np.array(list(functions_parsed[0]['return_type']))
        # check if return type contains dimensional information:
        if '<' in return_type_list:
            inds = np.where(return_type_list == '<')
            for i in inds[0]:
                #ind = return_type_list.index('<')
                if return_type_list[i+1] == 'D' or return_type_list[i+1] == '1' or return_type_list[i+1] == '2' or return_type_list[i+1] == '3' or return_type_list[i+1] == '4':
                    return_type_list[i+1] = 'D'
    else:
        return_type_list = np.array(['a','u','t','o'])

    return_type = return_type_list.tolist()
    return_type = "".join(return_type)
    # Header of object functions file
    gen.append_line("static constexpr {ret_type} {function_name}({type}<D, ScalarT> const& obj)".format(ret_type = return_type, function_name=function_name, type=type))
    gen.append_line("{")
    gen.indent()

    
    # 2nd pass -> sort according to dimensions (ascending order) or early-out if no function for 'type' found
    if len(functions_parsed) == 0:
        gen.append_line('static_assert(cc::always_false<{type}<D, ScalarT>>, "TODO: not yet implemented");'.format(type=type)) # TODO: Add "Should not be implemented"
        gen.unindent()
        gen.append_line("}")
        return

    functions_parsed.sort(key = lambda f : f['dim']) # sort according to dim in ascending order

    # 3rd pass -> write to code generator

    found_dim_d = False
    for f in functions_parsed:
        if f['dim'] != 'D':
            gen.append_line("if constexpr(D == {dimension})".format(dimension = f['dim']))
            gen.append_line("{")
            gen.indent()
            gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))
            gen.unindent()
            gen.append_line("}")
        else:
            if not found_dim_d: # dimension D
                found_dim_d = True
                if len(functions_parsed) > 1:
                    gen.append_line("else{")
                    gen.indent()
                    gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))
                    gen.unindent()
                    gen.append_line("}")
                else:
                    gen.append_line("return {function_name}(obj);".format(function_name = f['function_name']))
        
    if not found_dim_d:
        if len(functions_parsed) >= 1:
            gen.append_line("else{")
            gen.indent()
            gen.append_line('static_assert(cc::always_false<{type}<D, ScalarT>>, "TODO: not yet implemented");'.format(type=type))
            gen.unindent()
            gen.append_line("}")
        # else:
                #should not happen
    gen.unindent()
    gen.append_line("}")


# returning string containing the template information for 'type'
def get_type_template(type: str):
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

def generate_function_binary_symmetric(gen : code_generator, function_name : str, type_a : str, type_b : str, deserial_file):

    # get template info for the first type
    type_a_object_dim = False
    type_b_object_dim = False

    template_a = get_type_template(type_a)
    if "ObjectD" in template_a:
        type_a_object_dim = True
    
    # TODO: if type_b_object_dim gets true we have to generate overloaded functions!
    template_b = get_type_template(type_b)
    if "ObjectD" in template_b:
        type_b_object_dim = True

    # interpret format of the templates
    template_a_printable = adapt_template_format(template_a)
    template_b_printable = adapt_template_format(template_b)

    # TODO: Adapt the parsed template information to be able to be printed in the object function files

    # 1st iteration - pre pass - revised
    functions_parsed = []
    # iteration over all functions
    for i in deserial_file:
        if(i['function_declaration']['name'].startswith(function_name)):
            func_decl_params = i['function_declaration']['parameters']

            type_name_a = func_decl_params[0]['type_name']
            type_name_b = func_decl_params[1]['type_name']
            if ("<" in type_name_a):
                type_name_a = type_name_a[:type_name_a.index("<")]
            if("<" in type_name_b):
                type_name_b = type_name_b[:type_name_b.index("<")]

            # TODO: Maybe no longer required
            if not (func_decl_params[0]['type_name'].startswith(type_a) and func_decl_params[1]['type_name'].startswith(type_b)):
                continue

            if not (type_name_a == type_a and type_name_b == type_b):
                continue

            if not (func_decl_params[0]['domain_dim'] == func_decl_params[1]['domain_dim']):
                continue

            func_name_parsed = i['function_declaration']['name']

            domain_dim = func_decl_params[0]['domain_dim']
            object_dim = func_decl_params[0]['object_dim']

            # build object for specific function implementation
            function = {} #empty object
            function["function_name"] = func_name_parsed
            function["object_dim"] = object_dim
            function["domain_dim"] = domain_dim
            function["return_type"] = i['function_declaration']['return_type']
            function["func_decl_params"] = func_decl_params # TODO: Maybe do not need to write out all param info
            functions_parsed.append(function)

    # Extract the return type -> in-between pass
    return_type_list = []
    if(len(functions_parsed) > 0):
        return_type_list = np.array(list(functions_parsed[0]['return_type']))
        # check if return type contains dimensional information:
        if '<' in return_type_list:
            inds = np.where(return_type_list == '<')
            for i in inds[0]:
                #ind = return_type_list.index('<')
                if return_type_list[i+1] == 'D' or return_type_list[i+1] == '1' or return_type_list[i+1] == '2' or return_type_list[i+1] == '3' or return_type_list[i+1] == '4':
                    return_type_list[i+1] = 'D'
    else:
        return_type_list = np.array(['a','u','t','o'])

    return_type = return_type_list.tolist()
    return_type = "".join(return_type)

    # Header of object functions file
    gen.append_line("static constexpr {ret_type} {function_name}({type_a}{templ_a} const& obj_a, {type_b}{templ_b} const& obj_b)".format(ret_type = return_type, function_name=function_name, type_a=type_a, templ_a = template_a_printable, type_b = type_b, templ_b = template_b_printable))
    gen.append_line("{")
    gen.indent()

    # 2nd pass -> sort according to dimensions (ascending order) or early-out if no function for 'type' found
    if len(functions_parsed) == 0:
        gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a, templ_a = template_a_printable, type_b=type_b, templ_b = template_b_printable))
        gen.unindent()
        gen.append_line("}")
        return

    # TODO: Check if this always works
    # type with varying object and domain dim
    if(type_a_object_dim):
        functions_parsed.sort(key = lambda f : tuple(f['domain_dim'], f['object_dim'])) # sort according to dim in ascending order

    else:
        functions_parsed.sort(key = lambda f : f['domain_dim']) # sort according to dim in ascending order


    # 3rd pass -> write to code generator
    found_dom_D = False
    found_obj_D = False
    for f in functions_parsed:
        # objectDim and domainDim not D
        if f['domain_dim'] != 'D':
            object_dim_if = ""
            if(type_a_object_dim):
                if(f['object_dim'] != 'D'): # This case might never occur
                    object_dim_if = "and O == {}".format(f['object_dim'])

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

                    if not (type_a_object_dim or not f['object_dim'] == "D"):
                        continue

                    found_dom_D = True
                    found_obj_D = True

                    # no further ifs required here

                    if len(functions_parsed) > 1:
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
        if len(functions_parsed) >= 1:
            gen.append_line("else{")
            gen.indent()
            gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a,templ_a = template_a_printable, type_b=type_b, templ_b = template_b_printable))
            gen.unindent()
            gen.append_line("}")
        # else:
                #should not happen
    gen.unindent()
    gen.append_line("}")


    #gen.append_line("static constexpr auto {function_name}({type_a}<D, ScalarT> const& a, {type_b}<D, ScalarT> const& b)".format(function_name=function_name, type_a=type_a, type_b=type_b))
    #gen.append_line("{")
    #gen.indent()
    #gen.append_line('static_assert(cc::always_false<{type_a}<D, ScalarT>,{type_b}<D, ScalarT>>, "TODO: not yet implemented");'.format(type_a=type_a, type_b=type_b))
    #gen.unindent()
    #gen.append_line("}")

def generate_function_binary_asymmetric(gen : code_generator, function_name : str, type_a : str, type_b : str):
    gen.append_line("static constexpr auto {function_name}({type_a}<D, ScalarT> const& a, {type_b}<D, ScalarT> const& b)".format(function_name=function_name, type_a=type_a, type_b=type_b))
    gen.append_line("{")
    gen.indent()
    gen.append_line('static_assert(cc::always_false<{type_a}<D, ScalarT>,{type_b}<D, ScalarT>>, "TODO: not yet implemented");'.format(type_a=type_a, type_b=type_b))
    gen.unindent()
    gen.append_line("}")

# Generate the object functions for a given type
def generate_object_functions(type : str):
    gen = code_generator()
    gen.append_line("#pragma once")
    gen.newline()
    gen.append_line("#include <{}>".format(default_object_functions_path))
    gen.newline()
    gen.append_line("template <int D, class ScalarT>")
    gen.append_line("struct object_functions<{}<D, ScalarT>>".format(type))
    gen.append_line("{")
    gen.indent()

    # generate function descriptions for all unary functions
    for function in unary_functions:
        # deserialize json files - hard coded for the moment
        f = open('function_lists/' + function[1] + '.json')
        deserial_functions = json.load(f) # list format
        generate_function_unary(gen, function[0], type, deserial_functions)
        gen.newline()

    # generate function descriptions for all binary symmetric functions
    for function in binary_symmetric_functions:
        for other_type in common_types:
            f = open('function_lists/' + function[1] +'.json')
            deserial_functions = json.load(f) # list format
            generate_function_binary_symmetric(gen, function[0], type, other_type , deserial_functions)
            gen.newline()        

    # generate function descriptions for all binary symmetric functions
    for function in binary_asymmetric_functions:
        for other_type in all_types:
            generate_function_binary_asymmetric(gen, function, type, other_type)
            gen.newline()        

    gen.unindent()
    gen.append_line("};")
    
    filepath = object_functions_dir + type + ".hh"

    with open(filepath, "w") as file:
        file.write(gen.string)


### MAIN APP ###

# deserialize json files - hard coded for the moment
# f = open('function_lists/aabb.json')
# aabb_js = json.load(f) # list format

for type in common_types:
    generate_object_functions(type)
