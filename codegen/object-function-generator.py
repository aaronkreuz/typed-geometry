import os
import json
import numpy as np
import processing as ofp

# TODO: separate object_functions + object_function_uncommon

tg_src_root = "" # todo

#print("Total types: {}".format(len(all_types)))

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
def generate_function_unary(gen : ofp.code_generator, function_name : str, type, deserial_file):
    # 1st iterate through file and write functions into list incl. name and dimension
    # 2nd sort list according to dimension
    # 3rd write function to object file according to schema

    type_objectD = False
    
    # Requiring type template information
    templ_type = ofp.get_type_template(type, ofp.type_path)
    if('ObjectD' in templ_type):
        type_objectD = True

    # interpret format of the templates and remove identifiers of the template arguments
    templ_type_printable = ofp.template_format_values(ofp.adapt_template_format(templ_type))

    found_func = False

    functions_parsed = []

    # 1st: iterate over function info and store matching functions in 'functions_parsed'
    for f in deserial_file:
        if f['function_declaration']['name_prefix'] == function_name:
            func = ofp.parse_function_info_unary(f, function_name, type[0])
            if(len(func) > 0):
                functions_parsed.append(func)
 
    # Extract the return type
    return_type = ofp.get_return_type(functions_parsed)

    # Header of functions in object function file
    gen.append_line("static constexpr {ret_type} {function_name}({type}{templ} const& obj)".format(ret_type = return_type, function_name=function_name, type=type[0], templ = templ_type_printable))
    ofp.begin_scope(gen)
    
    # early-out if no function for 'type' found
    if len(functions_parsed) == 0:
        gen.append_line('static_assert(cc::always_false<{type}{templ}>, "TODO: not yet implemented");'.format(type=type[0], templ = templ_type_printable)) # TODO: Add "Should not be implemented"
        ofp.end_scope(gen)
        return

    #2nd: sort according to dimensions (ascending order) based on domain dim (and evtl. object dim)
    if not type_objectD:
        functions_parsed.sort(key = lambda f : f['domain_dim']) # sort according to dim in ascending order

    else:
        functions_parsed.sort(key = lambda f : tuple((f['domain_dim'], f['object_dim'])))

    # 3rd pass -> write to code generator based on type object-domain dependency
    if(type_objectD):
        ofp.write_unary_domain_object_d(gen, functions_parsed, type[0], templ_type_printable)
    
    else:
        ofp.write_unary_domain_d(gen, functions_parsed, type[0], templ_type_printable)

    ofp.end_scope(gen) # end of function

    return
    

# NOTE: Generating object function for binary symmetric functions
def generate_function_binary_symmetric(gen : ofp.code_generator, function_name : str, type_a, type_b, deserial_file):

    type_a_object_dim = False
    type_b_object_dim = False

    # getting template spec. for type_a and type_b
    template_a = ofp.get_type_template(type_a, ofp.type_path) 
    if "ObjectD" in template_a: # checking if type_a objectDim dependent
        type_a_object_dim = True
    
    template_b = ofp.get_type_template(type_b, ofp.type_path)
    if "ObjectD" in template_b: # checking if type_b objectDim dependent
        type_b_object_dim = True

    # interpret format of the templates and remove identifiers of the template arguments
    template_a_printable = ofp.template_format_values(ofp.adapt_template_format(template_a))
    template_b_printable = ofp.template_format_values(ofp.adapt_template_format(template_b))

    functions_parsed = [] # storing function info for functions matching function_name and type names

    # iteration over functions in file. Store if name equal to function name and types are matching
    for f in deserial_file:
        f_name_prefix = f['function_declaration']['name_prefix']

        if f_name_prefix == function_name:
            function = ofp.parse_function_info_binary_symmetric(f, function_name, type_a[0], type_b[0])
            if len(function) != 0:
                functions_parsed.append(function)

    # Extract the return type
    return_type = ofp.get_return_type(functions_parsed)

    # 2nd pass -> sort according to dimensions (ascending order) or early-out if no function for 'type' found
    if len(functions_parsed) == 0: # no functions parsed -> EARLY-OUT
        # Header of object functions file
        gen.append_line("static constexpr {ret_type} {function_name}({type_a}{templ_a} const& obj_a, {type_b}{templ_b} const& obj_b)".format(ret_type = return_type, function_name=function_name, type_a=type_a[0], templ_a = template_a_printable, type_b = type_b[0], templ_b = template_b_printable))
        gen.append_line("{")
        gen.indent()
        gen.append_line('static_assert(cc::always_false<{type_a}{templ_a},{type_b}{templ_b}>, "TODO: not yet implemented");'.format(type_a=type_a[0], templ_a = template_a_printable, type_b=type_b[0], templ_b = template_b_printable))
        gen.unindent()
        gen.append_line("}")
        return

    # TODO: Check if this always works -> another way of sorting when also 'type_b_object_dim'?
    ofp.sorting_funcs(functions_parsed, type_a_object_dim, type_b_object_dim)

    # 3rd pass -> write to code generator
    if(not type_a_object_dim and not type_b_object_dim):
        # Header of object functions file
        gen.append_line("static constexpr {ret_type} {function_name}({type_a}{templ_a} const& obj_a, {type_b}{templ_b} const& obj_b)".format(ret_type = return_type, function_name=function_name, type_a=type_a[0], templ_a = template_a_printable, type_b = type_b[0], templ_b = template_b_printable))
        ofp.begin_scope(gen)
        ofp.write_bin_symmetric_DomainD(gen, functions_parsed, type_a[0], type_b[0], template_a_printable, template_b_printable)
        ofp.end_scope(gen)

    if(type_a_object_dim and not type_b_object_dim):
        # A ODD and B not ODD
        gen.append_line("static constexpr {ret_type} {function_name}({type_a}{templ_a} const& obj_a, {type_b}{templ_b} const& obj_b)".format(ret_type = return_type, function_name=function_name, type_a=type_a[0], templ_a = template_a_printable, type_b = type_b[0], templ_b = template_b_printable))
        ofp.begin_scope(gen)
        ofp.write_bin_symmetric_TypeAObjectD(gen, functions_parsed, type_a[0], type_b[0], template_a_printable, template_b_printable)
        ofp.end_scope(gen)

    else: # special case with overloading -> B ODD and (A ODD or A not ODD)
        if(type_b_object_dim):
            # For every objectDim of Type B build up own function -> Separate 'functions_parsed' and call 'write_bin_symmetric_DomainD'
            # or call 'write_bin_symmetricTypeAObjectD' depending on whether Type A ODD or not ODD from 'processing.py' for every sub-list.
            functions_parsed_sep = ofp.separate_funcs(functions_parsed)
            for f_list in functions_parsed_sep:
                # fix the object domain of the template of type b
                objD_type_b = f_list[0]['params'][1]['object_dim']

                template_b_file = template_b_printable

                # TODO: check correctness
                if "<O" in template_b_printable:
                    start_obj_dim = template_b_printable.index("<O") + 1
                    end_obj_dim = start_obj_dim + 1
                    template_b_file = template_b_printable[:start_obj_dim] + objD_type_b + template_b_printable[end_obj_dim:]

                # objD_type_b_read = ofp.get_object_dim_from_name(template_b_printable)
                gen.append_line("static constexpr {ret_type} {function_name}({type_a}{templ_a} const& obj_a, {type_b}{templ_b} const& obj_b)".format(ret_type = return_type, function_name=function_name, type_a=type_a[0], templ_a = template_a_printable, type_b = type_b[0], templ_b = template_b_printable))
                
                ofp.begin_scope(gen)
                if not type_a_object_dim:
                    ofp.write_bin_symmetric_DomainD(gen, f_list, type_a[0], type_b[0], template_a_printable, template_b_file)

                else: # type_a_object_dim:
                    ofp.write_bin_symmetric_TypeAObjectD(gen, f_list, type_a[0], type_b[0], template_a_printable, template_b_file)
                
                ofp.end_scope(gen) # end of function
        
    return


# TODO
def generate_function_binary_asymmetric(gen : ofp.code_generator, function_name : str, type_a : str, type_b : str):
    gen.append_line("static constexpr auto {function_name}({type_a}<D, ScalarT> const& a, {type_b}<D, ScalarT> const& b)".format(function_name=function_name, type_a=type_a, type_b=type_b))
    gen.append_line("{")
    gen.indent()
    gen.append_line('static_assert(cc::always_false<{type_a}<D, ScalarT>,{type_b}<D, ScalarT>>, "TODO: not yet implemented");'.format(type_a=type_a, type_b=type_b))
    gen.unindent()
    gen.append_line("}")


# Generate the object functions for a given type
def generate_object_functions(type):

    common = False # storing info if type is a common type
    if type in ofp.common_types:
        common = True

    gen_common = ofp.code_generator()   # code generator for functions with only common type parameter
    gen_advanced = ofp.code_generator() # code generator for functions with at least one advanced type parameter
    gens = []

    if common:
        gens.append(gen_common) # if type is non-common, no file for the common case has to be generated
    gens.append(gen_advanced)
    
    for gen in gens:
        gen.append_line("#pragma once")
        gen.newline()
        gen.append_line("#include <{}>".format(ofp.default_object_functions_path))
        gen.newline()
        type_template = ofp.get_type_template(type, ofp.type_path)
        type_template = ofp.adapt_template_format(type_template)
        type_template_values = ofp.template_format_values(type_template)
        gen.append_line("template {templ}".format(templ = type_template))
        gen.append_line("struct object_functions<{typeA}{templ}>".format(typeA = type[0], templ = type_template_values))
        gen.append_line("{")
        gen.indent()

    # generate function descriptions for all unary functions
    for function in ofp.unary_functions:
        # deserialize json files - hard coded for the moment
        f = open(ofp.function_list_path + function[1] + '.json')
        deserial_functions = json.load(f) # list format
        if common:
            generate_function_unary(gen_common, function[0], type, deserial_functions)
            gen_common.newline()
        else:
            generate_function_unary(gen_advanced, function[0], type, deserial_functions)
            gen_advanced.newline()

    # generate function descriptions for all binary symmetric functions
    for function in ofp.binary_symmetric_functions:
        f = open(ofp.function_list_path + function[1] +'.json')
        deserial_functions = json.load(f) # list format

        if common:
            for other_type in ofp.common_types:
                generate_function_binary_symmetric(gen_common, function[0], type, other_type , deserial_functions)
                gen_common.newline()
        else:
            for other_type in ofp.common_types:
                generate_function_binary_symmetric(gen_advanced, function[0], type, other_type, deserial_functions)

        for other_type in ofp.advanced_types:
            generate_function_binary_symmetric(gen_advanced, function[0], type, other_type, deserial_functions)

    # generate function descriptions for all binary symmetric functions
    for function in ofp.binary_asymmetric_functions:

        if common:
            for other_type in ofp.common_types:
                generate_function_binary_asymmetric(gen_common, function, type, other_type)
                gen_common.newline()        
        else:
            for other_type in ofp.common_types:
                generate_function_binary_asymmetric(gen_advanced, function, type, other_type)
                gen_advanced.newline()

        for other_type in ofp.advanced_types:
            generate_function_binary_asymmetric(gen_advanced, function, type, other_type)
            gen_advanced.newline()

    for gen in gens:
        gen.unindent()
        gen.append_line("};")
    
    filepath_common = ofp.object_functions_dir_common + type[0] + ".hh"
    filepath_advanced = ofp.object_functions_dir_advanced + type[0] + ".hh"

    if common: # only generate common-case file if type is common
        with open(filepath_common, "w") as file:
            file.write(gen_common.string)

    with open(filepath_advanced, "w") as file:
        file.write(gen_advanced.string)


### MAIN APP ###

if not os.path.exists(ofp.object_functions_dir_common):
    os.makedirs(ofp.object_functions_dir_common)

if not os.path.exists(ofp.object_functions_dir_advanced):
    os.makedirs(ofp.object_functions_dir_advanced)

for type in ofp.all_types:
    generate_object_functions(type)
