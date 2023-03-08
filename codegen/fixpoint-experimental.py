import os
import json
import numpy as np
import processing as ofp

in_file_path = "function_list/"
type_path = "../src/typed-geometry/types/"

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
    ["intersection", "intersection"], # representation problem
    ["closest_points", "closest_points"],
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

all_types = common_types + advanced_types


# NOTE: There does not seem to be any rule for unary functions being applied by another function -> This case might be ignored
def fixpoint_step_unary(func_name: str, file_name: str, deserial_funcs, type):
    output_file_path = in_file_path + file_name

    type_objectD = False
    
    # Requiring type template information
    templ_type = ofp.get_type_template(type, type_path)
    if('ObjectD' in templ_type):
        type_objectD = True

    functions_parsed = []

    # parsing file
    for f in deserial_funcs:
        func = ofp.parse_function_info_unary(f, func_name, type[0])
        if len(func) > 0:
            functions_parsed.append(func)
    
    # check if an implementation is missing -> requires info if type is object-dim.-dependent
    found_domains = []

    for func in functions_parsed:
        domD = func['domain_dim']
        objD = func['object_dim']
        if type_objectD:
            found_domains.append((objD, domD))
        else:
            found_domains.append(domD)

    # identify missing cases:
    if ("O","D") in found_domains or "D" in found_domains: # does this work?
        return # all cases handled
    
    missing_cases = []
    
    if type_objectD:
        for obj_i in ["1","2","3"]: # TODO: are this all possible obj. dims?
            if (obj_i,"D") in found_domains:
                continue
            
            dom_i = obj_i
            while int(dom_i) <= (int(obj_i) + 1):
                if not (obj_i, dom_i) in found_domains:
                    missing_cases.append((obj_i, dom_i))
                dom_i = str(int(dom_i) + 1)

    else:
        if "D" in found_domains:
            return # all cases handled
        for dom_i in ["2", "3"]:
            if not dom_i in found_domains:
                missing_cases.append(dom_i)

    # missing cases stored in "missing_cases"
    if len(missing_cases) == 0:
        return # no missing cases found
    
    # iterate over missing cases
    for mc in missing_cases:
        # check for corresponding rule
        return

    return


def get_type_minus_template(type: str):
    if '<' in type:
        end_idx = type.index('<')
        type = type[:end_idx]
    
    return type


def fixpoint_step_binary_symmetric(func_name: str, file_name: str, deserial_funcs, type_a, type_b):
    output_file_path = in_file_path + file_name

    typeA_objectD = False
    typeB_objectD = False
    
    # Requiring type template information
    templ_type = ofp.get_type_template(type_a, type_path)
    if('ObjectD' in templ_type):
        typeA_objectD = True

    templ_type = ofp.get_type_template(type_b, type_path)
    if('ObjectD' in templ_type):
        typeB_objectD = True

    functions_parsed = []

    # parsing file
    for f in deserial_funcs:
        if(f['function_declaration']['name'].startswith(func_name)): # TODO: forbid functions with same prefix. startswith check is too weak.
            func = ofp.parse_function_info_binary_symmetric(f, func_name, type_a[0], type_b[0])
            if len(func) > 0:
                functions_parsed.append(func)
    
    # check if an implementation is missing -> requires info if type is object-dim.-dependent
    found_domains = []

    # store domain combinations that are handled
    for func in functions_parsed:
        function_paramsA = func['params'][0]
        function_paramsB = func['params'][1]
        domD = function_paramsA['domain_dim'] # domain dimension equal for type A and B
        objD_A = function_paramsA['object_dim']
        objD_B = function_paramsB['object_dim']

        if typeA_objectD and typeB_objectD:
            found_domains.append((objD_A, objD_B, domD))
            continue
        
        if typeA_objectD and not typeB_objectD:
            found_domains.append((objD_A, domD))
            continue

        if not typeA_objectD and typeB_objectD:
            found_domains.append((objD_B, domD))
            continue

        else: # A not ODD and B not ODD (Object Domanin Dependent)
            found_domains.append(domD)

        
    # identify missing cases:
    if ("O","O","D") in found_domains or ("O","D") in found_domains or "D" in found_domains: # does this work?
        return # all cases handled
    
    missing_cases = []

    if typeA_objectD and typeB_objectD:
        for objA_i in ["1","2","3"]:
            for objB_i in ["1","2","3"]:
                if (objA_i, objB_i, "D") in found_domains:
                    continue

                dom_i = max(int(objA_i), int(objB_i))
                while int(dom_i) <= 3:
                    if not (objA_i, objB_i, dom_i) in found_domains:
                        missing_cases.append((objA_i, objB_i, dom_i))
                    dom_i = str(int(dom_i)+1)
    
    if (typeA_objectD and not typeB_objectD) or (typeB_objectD and not typeA_objectD):
        for obj_i in ["1","2","3"]: # TODO: are this all possible obj. dims?
            if (obj_i,"D") in found_domains:
                continue
            
            dom_i = obj_i
            while int(dom_i) <= (int(obj_i) + 1): # TODO: Maybe instead of "(int(obj_i)+1)" just "3" as above
                if not (obj_i, dom_i) in found_domains:
                    missing_cases.append((obj_i, dom_i))
                dom_i = str(int(dom_i) + 1)

    if not typeA_objectD and not typeB_objectD:
        if "D" in found_domains:
            return # all cases handled
        for dom_i in ["2", "3"]:
            if not dom_i in found_domains:
                missing_cases.append(dom_i)

    # missing cases stored in "missing_cases" (domain info of missing case)
    if len(missing_cases) == 0:
        return # no missing cases found
    
    #print(missing_cases)
    
    lam_func_decl = lambda func: func["function_declaration"]["parameters"] # lambda to ease accessing parameter data within filter-function
    # TODO: iterate over missing cases
    for mc in missing_cases:
        l = []
        
        ### check for symmetry in deserial funcs ###
        l = list(filter(lambda func: (get_type_minus_template(lam_func_decl(func)[0]["type_name"]) == type_b[0]) and (get_type_minus_template(lam_func_decl(func)[1]["type_name"]) == type_a[0]) and (ofp.get_func_prefix_binary(func["function_declaration"]["name"]) == func_name), deserial_funcs))
        if len(mc) == 1:
            l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc, deserial_funcs))
            if len(l) > 0:
                # taking the first matching symmetric implementation
                function_new = l[0] 
                # swap the parameters
                lam_func_decl(function_new)[0] = lam_func_decl(l[0])[1]
                lam_func_decl(function_new)[1] = lam_func_decl(l[0])[0]
                # append to deserial funcs
                deserial_funcs.append(function_new)
                # TODO: DEBUG
                continue

        if len(missing_cases[0]) == 2:
            if typeA_objectD:
                l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc[1] and lam_func_decl(func)[0]["object_dim"] == mc[0], deserial_funcs))
            elif typeB_objectD:
                l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc[1] and lam_func_decl(func)[1]["object_dim"] == mc[0], deserial_funcs))
            
            if len(l) > 0:
                # print("Case 2: ")
                # print(l) # DEBUG
                # TODO: append according function to deserial_funcs
                continue

        if len(missing_cases[0]) == 3:
            l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc[2] and lam_func_decl(func)[0]["object_dim"] == mc[0] and lam_func_decl(func)[1]["object_dim"] == mc[1], deserial_funcs))

            if len(l) > 0:
                # print("Case 3: ")
                # print(l) # DEBUG
                # TODO: append according function to deserial_funcs
                continue

        print(l)

        ### check for rules ###

        # TODO: check for corresponding rule in ruleset

        # NOTE: format of elements in missing cases may differ -> 3 cases to handle

        # TODO: write deserial_funcs to file if changes appeared
        
        return

    return


def fixpoint_iteration(type):
    # unary fixpoint-step -> TODO: Nothin happens here probably
    for func in unary_functions:
        f = open('function_lists/' + func[1] + ".json")
        deserial_functions = json.load(f) # list format
        fixpoint_step_unary(func[0], func[1], deserial_functions, type)

    # binary symmetric fixpoint-step
    for func in binary_symmetric_functions:
        f = open('function_lists/' + func[1] + ".json")
        deserial_functions = json.load(f)
        for other_type in common_types:
            fixpoint_step_binary_symmetric(func[0], func[1], deserial_functions, type, other_type)
        
    return


### MAIN ###
# TODO: Maybe just iterate over content of "function_lists/"?
for type in all_types:
    fixpoint_iteration(type)