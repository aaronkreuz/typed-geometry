import os
import json
import numpy as np

# TODO: separate object_functions + object_function_uncommon

common_types = [
    "aabb",
    "pos",
    "ray",
    "line",
    "seg",
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
    # "intersects",
    # "intersection",  # representation problem
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

with open(default_object_functions_path, "w") as f:
    f.write(default_object_functions)


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
    
    
    # TODO: handle return types
    found_func = False

    # 1st iteration - pre pass
    functions_parsed = [] # empty list
    # TODO functions_parsed_tl[] and then for each found function functions_parsed_tl.append[functions_parsed]...
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



    # TODO logic 
    # find type related functions in deserialized json lists
    # gen.append_line("static constexpr auto {function_name}({type}<D, ScalarT> const& obj)".format(function_name=function_name, type=type))
    # gen.append_line("{")
    # gen.indent()
# 
    # for i in deserial_file:
# 
    #     if(i['function_declaration']['name'].startswith(function_name)):
    #         func_decl_params = i['function_declaration']['parameters']
# 
    #         # check if function params contain type (requirement)
    #         if not any(d['type_name'].startswith(type) for d in func_decl_params):
    #             continue
# 
    #         # DEBUG
    #         print(i)
    #         found_func = True
    #         # write this function:
    #         dim = get_dim_from_name(i["function_declaration"]["name"])
# 
    #         if dim == 'D': # special case -> function can be applied for every dimension
    #             gen.append_line("return {function_name}({param_name});".format(function_name = i["function_declaration"]["name"], param_name = func_decl_params[0]["parameter_name"]))
# 
    #         else: # dimension specific implementation of the specific function
    #             # if for dim-case distinction
    #             gen.append_line("if constexpr(D == {dimension})".format(dimension = dim))
    #             gen.append_line("{")
    #             gen.indent
# 
    #             # specific dim function
    #             gen.append_line("static constexpr {return_type} {function_name}({type}<{D}ScalarT> const& {obj})".format(return_type = i["function_declaration"]["return_type"] ,function_name=function_name, type=type, D = dim+", ", obj = func_decl_params[0]["parameter_name"]))
    #             gen.append_line("{")
    #             gen.indent()
# 
    #             # TODO: really required?
    #             return_line = "return {function_name}(".format(function_name = i["function_declaration"]["name"])#, param_name = func_decl_params[0]["parameter_name"])
    #             for param in func_decl_params:
    #                 return_line += "{parameter_name}".format(parameter_name = param["parameter_name"] + ", ")
# 
    #             return_line.removesuffix(", ")
    #             return_line += ");"
# 
    #             gen.append_line("return {function_name}({param_name});".format(function_name = i["function_declaration"]["name"], param_name = func_decl_params[0]["parameter_name"]))
    #             gen.unindent
    #             # close function
    #             gen.append_line("}")
# 
    #             gen.unindent()
    #             gen.append_line("}")
# 
    # gen.unindent()
    # gen.append_line("}")

    # could not find a type-related function in the specific file
    # if not found_func:
    #     gen.append_line("static constexpr auto {function_name}({type}<D, ScalarT> const& obj)".format(function_name=function_name, type=type))
    #     gen.append_line("{")
    #     gen.indent()
    #     gen.append_line('static_assert(cc::always_false<{type}<D, ScalarT>>, "TODO: not yet implemented");'.format(type=type)) # TODO: Add "Should not be implemented"
    #     gen.unindent()
    #     gen.append_line("}")



def generate_function_binary_symmetric(gen : code_generator, function_name : str, type_a : str, type_b : str):
    gen.append_line("static constexpr auto {function_name}({type_a}<D, ScalarT> const& a, {type_b}<D, ScalarT> const& b)".format(function_name=function_name, type_a=type_a, type_b=type_b))
    gen.append_line("{")
    gen.indent()
    gen.append_line('static_assert(cc::always_false<{type_a}<D, ScalarT>,{type_b}<D, ScalarT>>, "TODO: not yet implemented");'.format(type_a=type_a, type_b=type_b))
    gen.unindent()
    gen.append_line("}")

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
        for other_type in all_types:
            generate_function_binary_symmetric(gen, function, type, other_type)
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
