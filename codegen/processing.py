import json
import os
import numpy as np
import object_type as ot

# NOTE: file containing shared functionalities

# file paths
type_path = "../src/typed-geometry/types/"
src_function_path = "../src/typed-geometry/functions/objects/"
function_list_path = "function_lists/"
renamed_files_path = "renamed_files/"
object_functions_dir_common = "typed-geometry/object-functions/"
object_functions_dir_advanced = "typed-geometry/object-functions-advanced/"
default_object_functions_path ="typed-geometry/object_functions.hh" # todo
function_list_path_test = "function_lists_test/"
rules_path = "rules/"

# types
common_types = [
    #[type_name, file_name]
    ["aabb", "aabb"],
    ["pos", "pos"],
    ["ray", "ray"],
    ["line", "line"],
    ["segment", "segment"],
    ["sphere", "sphere"],
    ["triangle", "triangle"],
    ["plane", "plane"]
]

advanced_types = [
    #[type_name, file_name]
    ["aabb_boundary", "aabb"],
    ["box", "box"],
    ["box_boundary", "box"],
    ["capsule", "capsule"], # currently only 3d
    ["capsule_boundary", "capsule"],# currently only 3d
    ["cone", "cone"],
    ["cone_boundary", "cone"]
    #"cone_boundary_no_caps",
    #"cylinder",
    #"cylinder_boundary",
    #"cylinder_boundary_no_caps",
    #"ellipse",
    #"ellipse_boundary",
    #"frustum", # currently only 3d
    #"halfspace",
    #"hemisphere",
    #"hemisphere_boundary",
    #"hemisphere_boundary_no_caps",
    #"inf_cone",
    #"inf_cone_boundary",
    #"inf_cylinder",
    #"inf_cylinder_boundary",
    #"inf_frustum", # currently only 3d
    # "polygon", # not yet implemented
    # "polyline", # not yet implemented
    # "pyramid", # difficult due to varying base
    #"quad", # difficult, because currently no guarantee that planar
    #"sphere_boundary",
    #"disk",
    #"disk_boundary",
    # "circle", # same as disc_boundary
    # "tube", # same as cylinder_boundary_no_caps
    # "inf_tube", # same as inf_cylinder_boundary
    ]

# function types
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
    #[func_name, file_name]
    ["intersects", "intersection"],
    ["closest_points", "closest_points"],
    ["intersection", "intersection"], # representation problem
    ["distance", "distance"],
    ["distance_sqr", "distance"]
]

# TODO
binary_asymmetric_functions = [
    #["project", "project"],
    # "intersection_parameter",
    # "intersection_parameters",
    # "contains"  # potentially impl difficulty
]
    

all_functions = unary_functions + binary_symmetric_functions + binary_asymmetric_functions
all_types = common_types + advanced_types


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
def get_type_template(type_name: str, file_name: str, type_path: str):
    if (type_name +'.hh') in os.listdir(type_path):
        in_file = type_path + type[1] +'.hh'
    else:
        in_file = type_path + "objects/" + file_name + '.hh'

    text = open(in_file, "r").read()

    lines = text.split('\n')
    line_index = 0

    while line_index < len(lines):
        line_temp = lines[line_index]

        if line_temp.startswith('template'):
            line_next = lines[line_index+1]

            if type_name in line_next:
                start_ind = line_next.index(type_name)
                if not (start_ind + len(type_name) > (len(line_next) - 1)):
                    if not (line_next[start_ind + len(type_name)] != " " or line_next[start_ind + len(type_name)] != ";"):
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
    
    if not (func['function_declaration']['name_prefix'] == function_name):
        return {} # TODO: check already performed?

    func_decl_params = func['function_declaration']['parameters']

    # check if function params contain type (requirement)
    type_name =  func_decl_params[0]['type_name']
    type_name_prefix = type_name[:]
    if ('<' in type_name_prefix):
        type_name_prefix = type_name_prefix[:type_name.index('<')]

    boundary_tag = False
    if "boundary" in type:
        boundary_tag = True

    # check if types are matching - considering also boundary tags
    if not type_name_prefix == type:
        if not type.startswith(type_name_prefix) and not (boundary_tag and ("TraitsT" in type_name)):
            return {} # types not matching

    # build object for specific function implementation
    function = {} #empty object
    function["function_name"] = func['function_declaration']['name']
    function["domain_dim"] = func_decl_params[0]['domain_dim']
    function["object_dim"] = func_decl_params[0]['object_dim']
    function["return_type"] = func['function_declaration']['return_type']
    function["body"] = ""
    if func["function_declaration"]["name"] == "":
        function["body"] = func["body"]

    return function


# NOTE: parse relevant information of the given function and store info in dictionary (binary sym. function case)
def parse_function_info_binary_symmetric(func, function_name: str, type_a: str, type_b: str):
    if not (func['function_declaration']['name_prefix'] == function_name):
        return {} # TODO: check already performed?
    
    func_decl_params = func['function_declaration']['parameters']

    if(len(func_decl_params) != 2): # ensure 2 parameters
        return {}
    
    type_name_a = func_decl_params[0]['type_name']
    type_name_b = func_decl_params[1]['type_name']
    type_name_a_prefix = type_name_a[:]
    type_name_b_prefix = type_name_b[:]

    boundary_tag_a = False
    boundary_tag_b = False

    # boundary tag a
    if "boundary" in type_a:
        boundary_tag_a = True
    # boundary tag b
    if "boundary" in type_b:
        boundary_tag_b = True

    if ("<" in type_name_a):
        type_name_a_prefix = type_name_a[:type_name_a.index("<")]
    if ("<" in type_name_b):
        type_name_b_prefix = type_name_b[:type_name_b.index("<")]
    
    # check if types are matching - considering also boundary tags
    if not (type_name_a_prefix == type_a):
        if not type_a.startswith(type_name_a_prefix) and not (boundary_tag_a and ("TraitsT" in type_name_a)):
            return {}
     
    if not (type_name_b_prefix == type_b):
        if not type_b.startswith(type_name_b_prefix) and not (boundary_tag_b and ("TraitsT" in type_name_b)):
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
    function["symmetric"] = func["symmetric_implementation"]
    function["body"] = ""
    if func_name_parsed == "": # in case of rule-generated function-entry store also the body
        function["body"] = func["body"]
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


def generate_object_function_body_unary(gen: code_generator, func):
    if func["function_name"] == "": # generated by rule (no real function exists)
        gen.append_line("// GENERATED BY RULE (UNARY)")
        # insert body -> TODO: Rename functions in Body
        body_lines = func["body"][:]
        if "AAA" in body_lines:
            body_lines = body_lines.replace("AAA", "obj")

        body_lines = body_lines.split("\n")
        for line in body_lines:
            gen.append_line(line)
    else:
        gen.append_line("return {function_name}(obj);".format(function_name = func['function_name']))

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
            generate_object_function_body_unary(gen, f)
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
            generate_object_function_body_unary(gen, f)
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
            generate_object_function_body_unary(gen, f)
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
                generate_object_function_body_unary(gen, f)
                end_scope(gen)

            else:
                generate_object_function_body_unary(gen, f)

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
            generate_object_function_body_unary(gen, f)
            end_scope(gen)
            func_counter += 1
            continue
        
        # case 2: domain dim is abitrary
        if dom_d == 'D' and not found_dom_d:
            found_dom_d = True
            if func_counter > 0:
                gen.append_line("else")
                begin_scope(gen)
                generate_object_function_body_unary(gen, f)
                end_scope(gen)
            else:
                generate_object_function_body_unary(gen, f)
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

def generate_object_function_body_binary(gen: code_generator, f):
    if f["symmetric"]: # symmetric generated
        gen.append_line("// SYMMETRY")
        gen.append_line("return {function_name}(obj_b, obj_a);".format(function_name = f['function_name']))

    elif f["function_name"] == "": # generated by rule (no real function exists)
        gen.append_line("// GENERATED BY RULE")
        # insert body -> TODO: Rename functions in Body
        body_lines = f["body"][:]
        if "AAA" in body_lines:
            body_lines = body_lines.replace('AAA','obj_a')
        if "BBB" in body_lines:
            body_lines = body_lines.replace("BBB","obj_b")

        body_lines = body_lines.split("\n")
        for line in body_lines:
            gen.append_line(line)
    else:
        gen.append_line("return {function_name}(obj_a, obj_b);".format(function_name = f['function_name']))

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
            generate_object_function_body_binary(gen, f)
            end_scope(gen)

            func_counter += 1
            continue

        # Case 2: domainDim D and objectDim not O
        if dom_D == 'D' and object_D != 'O':
            found_dom_d = True
            gen.append_line("if constexpr(O == {object_dim})".format(object_dim = object_D))
            begin_scope(gen)
            generate_object_function_body_binary(gen, f)
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
                generate_object_function_body_binary(gen, f)
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
                generate_object_function_body_binary(gen, f)
                end_scope(gen)

            else:
                generate_object_function_body_binary(gen, f)

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
            # case distinction -> function per rule or parsed?
            generate_object_function_body_binary(gen, f)
            end_scope(gen)
            func_counter += 1

        else: # dom == D
            if not found_D: # dom D not reached before
                found_D = True
                if(func_counter > 0):
                    gen.append_line("else")
                    begin_scope(gen)
                    generate_object_function_body_binary(gen, f)
                    end_scope(gen)
                    # TODO: HERE TO RETURN? -> Reached else-case
                    break

                if(func_counter == 0):
                    generate_object_function_body_binary(gen, f)
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

# generate function entry by rule application
def generate_function_entry_binary(rule, obj_dim_a: str, obj_dim_b: str, dom_dim: str, type_a, type_b):
    typeA_objectD = False
    typeB_objectD = False

    # Requiring type template information
    templ_type_a = get_type_template(type_a.get_name(), type_a.get_file_name(), type_path)
    if('ObjectD' in templ_type_a):
        typeA_objectD = True

    templ_type_b = get_type_template(type_b.get_name(), type_b.get_file_name(), type_path)
    if('ObjectD' in templ_type_b):
        typeB_objectD = True

    boundary_tag_a = False
    boundary_tag_b = False
    if "boundary" in type_a[0]:
        boundary_tag_a = True
    if "boundary" in type_b[0]:
        boundary_tag_b = True

    if obj_dim_a == "":
        obj_dim_a = dom_dim

    if obj_dim_b == "":
        obj_dim_b = dom_dim

    function = {}

    # do not require template-parameters
    function["template_parameters"] = []
    
    # function declaration
    function_declaration = {}
    function_declaration["modifiers"] = []
    function_declaration["name_prefix"] = rule["implementee"] # function that is actually implemented

    # parameters
    parameters = []
    param_a = {}
    type_name_a = type_a[0] + templ_type_a
    # adapting the template

    if "class ScalarT" in type_name_a:
        type_name_a.replace("class ScalarT", "ScalarT")

    if not typeA_objectD:
        if "int D" in type_name_a:
            type_name_a.replace("int D", dom_dim)
        if "int DomainD" in type_name_a:
            type_name_a.replace("int DomainD", dom_dim)
        
    if typeA_objectD:
        if "int DomainD = ObjectD" in type_name_a:
            type_name_a.replace("int DomainD = ObjectD", obj_dim_a)

    if boundary_tag_a:
        if "class TraitsT = default_object_tag" in type_name_a:
            type_name_a.replace("class TraitsT = default_object_tag", "boundary_tag")
    elif ", class TraitsT = default_object_tag" in type_name_a:
        type_name_a.replace(", class TraitsT = default_object_tag", "")
        

    param_a["type_name"] = type_name_a

    param_a["parameter_name"] = "AAA" # TODO: placeholder
    param_a["default_value"] = ""
    param_a["domain_dim"] = dom_dim
    param_a["object_dim"] = obj_dim_a

    param_b = {}
    type_name_b = type_b[0] + templ_type_b

    if "class ScalarT" in type_name_b:
        type_name_b.replace("class ScalarT", "ScalarT")

    if not typeB_objectD:
        if "int D" in type_name_b:
            type_name_b.replace("int D", dom_dim)
        if "int DomainD" in type_name_b:
            type_name_b.replace("int DomainD", dom_dim)
        
    if typeA_objectD:
        if "int DomainD = ObjectD" in type_name_b:
            type_name_b.replace("int DomainD = ObjectD", obj_dim_b)

    if boundary_tag_b:
        if "class TraitsT = default_object_tag" in type_name_b:
            type_name_b.replace("class TraitsT = default_object_tag", "boundary_tag")
    elif ", class TraitsT = default_object_tag" in type_name_b:
            type_name_b.replace(", class TraitsT = default_object_tag", "")

    param_b["type_name"] = type_name_b 
    param_b["parameter_name"] = "BBB" # TODO: placeholder
    param_b["default_value"] = ""
    param_b["domain_dim"] = dom_dim
    param_b["object_dim"] = obj_dim_b

    parameters.append(param_a)
    parameters.append(param_b)

    function_declaration["parameters"] = parameters

    function_declaration["return_type"] = "auto" # TODO -> return correct type

    # NOTE: func name is empty because no real function exists -> can be used to identify function generated by rule application in the object_function generation
    function_declaration["name"] = ""

    function["function_declaration"] = function_declaration

    # TODO: Rename function names in rule body!!

    function["body"] = rule["implementation"]    
    function["symmetric_implementation"] = False

    return function