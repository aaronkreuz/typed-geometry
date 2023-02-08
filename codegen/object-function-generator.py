import os
import json
import numpy as np
import processing as ofp

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
    "box_boundary",
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
    #["signed_distance", "distance"]
]

binary_symmetric_functions = [
    ["intersects", "intersection"],
    ["intersection", "intersection"], # representation problem
    ["closest_points", "closest_points"],
    ["distance", "distance"]
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

# NOTE: Generating object function for unary functions
# TODO: Tidy up!
def generate_function_unary(gen : ofp.code_generator, function_name : str, type: str, deserial_file):
    # 1st iterate through file and write functions into list incl. name and dimension
    # 2nd sort list according to dimension
    # 3rd write function to object file according to schema (see notes)
    
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
            dim = ofp.get_dim_from_name(func_name_parsed)

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
    

# NOTE: Generating object function for binary symmetric functions
def generate_function_binary_symmetric(gen : ofp.code_generator, function_name : str, type_a : str, type_b : str, deserial_file):

    # get template info for the first type
    type_a_object_dim = False
    type_b_object_dim = False

    template_a = ofp.get_type_template(type_a, type_path)
    if "ObjectD" in template_a:
        type_a_object_dim = True
    
    # TODO: if type_b_object_dim gets true we have to generate overloaded functions!
    template_b = ofp.get_type_template(type_b, type_path)
    if "ObjectD" in template_b:
        type_b_object_dim = True

    # interpret format of the templates
    template_a_printable = ofp.adapt_template_format(template_a)
    template_b_printable = ofp.adapt_template_format(template_b)

    # 1st iteration - pre pass - revised
    functions_parsed = []

    # iteration over functions in file. Store if name equal to function name and types are matching
    for i in deserial_file:
        if(i['function_declaration']['name'].startswith(function_name)): # TODO: forbid functions with same prefix. startswith check is too weak.
            function = ofp.parse_function_info_binary_symmetric(i, function_name, type_a, type_b)
            if len(function) != 0:
                functions_parsed.append(function)

    # Extract the return type -> in-between pass
    return_type = ofp.get_return_type(functions_parsed)

    # 2nd pass -> sort according to dimensions (ascending order) or early-out if no function for 'type' found
    if len(functions_parsed) == 0: # no functions parsed -> EARLY-OUT
        # Header of object functions file
        gen.append_line("static constexpr {ret_type} {function_name}({type_a}{templ_a} const& obj_a, {type_b}{templ_b} const& obj_b)".format(ret_type = return_type, function_name=function_name, type_a=type_a, templ_a = template_a_printable, type_b = type_b, templ_b = template_b_printable))
        gen.append_line("{")
        gen.indent()
        gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a, templ_a = template_a_printable, type_b=type_b, templ_b = template_b_printable))
        gen.unindent()
        gen.append_line("}")
        return

    # TODO: Check if this always works -> another way of sorting when also 'type_b_object_dim'?
    ofp.sorting_funcs(functions_parsed, type_a_object_dim, type_b_object_dim)

    # 3rd pass -> write to code generator
    if(not type_a_object_dim and not type_b_object_dim):
        # Header of object functions file
        gen.append_line("static constexpr {ret_type} {function_name}({type_a}{templ_a} const& obj_a, {type_b}{templ_b} const& obj_b)".format(ret_type = return_type, function_name=function_name, type_a=type_a, templ_a = template_a_printable, type_b = type_b, templ_b = template_b_printable))
        ofp.begin_scope(gen)
        ofp.write_bin_symmetric_DomainD(gen, functions_parsed, type_a, type_b, template_a_printable, template_b_printable)
        # ending scope included in 'write_bin_symmetric_DomainD'

    if(type_a_object_dim and not type_b_object_dim):
        # A ODD and B not ODD
        gen.append_line("static constexpr {ret_type} {function_name}({type_a}{templ_a} const& obj_a, {type_b}{templ_b} const& obj_b)".format(ret_type = return_type, function_name=function_name, type_a=type_a, templ_a = template_a_printable, type_b = type_b, templ_b = template_b_printable))
        ofp.begin_scope(gen)
        ofp.write_bin_symmetric_TypeAObjectD(gen, functions_parsed, type_a, type_b, template_a_printable, template_b_printable)
        # ending scope included in 'write_bin_symmetric_TypeAObjectD'
    
    else: # special case with overloading -> B ODD and (A ODD or A not ODD)
        if(type_b_object_dim):
            # For every objectDim of Type B build up own function -> Separate 'functions_parsed' and call 'write_bin_symmetric_DomainD'
            # or call 'write_bin_symmetricTypeAObjectD' depending on whether Type A ODD or not ODD from 'processing.py' for every sub-list.
            functions_parsed_sep = ofp.separate_funcs(functions_parsed)
            for f_list in functions_parsed_sep:
                # fix the object domain of the template of type b
                objD_type_b = f_list[0]['params'][1]['object_dim']

                if "int O" in objD_type_b:
                    start_obj_dim = template_b_printable.index("O")
                    template_b_printable = template_b_printable[:start_obj_dim] + objD_type_b + template_b_printable[start_obj_dim + 1:]

                # objD_type_b_read = ofp.get_object_dim_from_name(template_b_printable)
                gen.append_line("static constexpr {ret_type} {function_name}({type_a}{templ_a} const& obj_a, {type_b}{templ_b} const& obj_b)".format(ret_type = return_type, function_name=function_name, type_a=type_a, templ_a = template_a_printable, type_b = type_b, templ_b = template_b_printable))
                ofp.begin_scope(gen)
                ofp.write_bin_symmetric_DomainD(gen, f_list, type_a, type_b, template_a_printable, template_b_printable)


    #gen.append_line("static constexpr auto {function_name}({type_a}<D, ScalarT> const& a, {type_b}<D, ScalarT> const& b)".format(function_name=function_name, type_a=type_a, type_b=type_b))
    #gen.append_line("{")
    #gen.indent()
    #gen.append_line('static_assert(cc::always_false<{type_a}<D, ScalarT>,{type_b}<D, ScalarT>>, "TODO: not yet implemented");'.format(type_a=type_a, type_b=type_b))
    #gen.unindent()
    #gen.append_line("}")

# TODO
def generate_function_binary_asymmetric(gen : ofp.code_generator, function_name : str, type_a : str, type_b : str):
    gen.append_line("static constexpr auto {function_name}({type_a}<D, ScalarT> const& a, {type_b}<D, ScalarT> const& b)".format(function_name=function_name, type_a=type_a, type_b=type_b))
    gen.append_line("{")
    gen.indent()
    gen.append_line('static_assert(cc::always_false<{type_a}<D, ScalarT>,{type_b}<D, ScalarT>>, "TODO: not yet implemented");'.format(type_a=type_a, type_b=type_b))
    gen.unindent()
    gen.append_line("}")

# Generate the object functions for a given type
def generate_object_functions(type : str):
    gen = ofp.code_generator()
    gen.append_line("#pragma once")
    gen.newline()
    gen.append_line("#include <{}>".format(default_object_functions_path))
    gen.newline()
    # TODO: correct template!
    type_template = ofp.get_type_template(type, type_path)
    type_template = ofp.adapt_template_format(type_template)
    type_template_values = ofp.template_format_values(type_template)
    gen.append_line("template {templ}".format(templ = type_template))
    gen.append_line("struct object_functions<{typeA}{templ}>".format(typeA = type, templ = type_template_values))
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
