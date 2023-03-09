import os
import json
import numpy as np
import processing as ofp
import copy
import time # temporary

# load common rules from file
# TODO: there can also be rules that are only applicable for specific type of functions
r = open(ofp.rules_path + "common_rules_binary" + ".json") 
common_rules_sym = json.load(r) # list format


# NOTE: There does not seem to be any rule for unary functions being applied by another function -> This case might be ignored
def fixpoint_step_unary(func_name: str, file_name: str, deserial_funcs, type):
    output_file_path = ofp.function_list_path + file_name

    type_objectD = False
    
    # Requiring type template information
    templ_type = ofp.get_type_template(type, ofp.type_path)
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
        return False # all cases handled
    
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
            return False # all cases handled
        for dom_i in ["2", "3"]:
            if not dom_i in found_domains:
                missing_cases.append(dom_i)

    # missing cases stored in "missing_cases"
    if len(missing_cases) == 0:
        return False # no missing cases found
    
    # iterate over missing cases
    for mc in missing_cases:
        # check for corresponding rule
        return False

    return False


def get_type_minus_template(type: str):
    if '<' in type:
        end_idx = type.index('<')
        type = type[:end_idx]
    return type


# NOTE: check if requirements for rule application are fulfilled
def are_implemented(rule, type_a: str, type_b: str):
    # iterating over implementers that have to be implemented
    for impl in rule["implementer"]: # TODO: does this also work if rule["implementers"] is not iterable? i.e. len == 1
        # open corresponding file by looking up table
        funcs = list(filter(lambda func: func[0] == impl, ofp.all_functions))
        if len(funcs) == 0: # should not happen
            return False
        func = funcs[0]
        # open the corresponding json file from "function_lists"
        f = open(ofp.function_list_path + func[1] + ".json", "r")
        funcs_implementer = json.load(f) # list format

        filtered_funcs = list(filter(lambda func: (func["function_declaration"]["name_prefix"] == impl), funcs_implementer))
        filtered_funcs = list(filter(lambda func: get_type_minus_template(func["function_declaration"]["parameters"][0]["type_name"]) == type_a, filtered_funcs))
        if type_b != "": # binary func
            filtered_funcs = list(filter(lambda func: get_type_minus_template(func["function_declaration"]["parameters"][1]["type_name"]) == type_b, filtered_funcs))

        if len(filtered_funcs) == 0: # implementation missing, can't apply rule
            return False
        
        # TODO: Check for boundary tag
        # if "boundary" in type_a:

        
    return True


def fixpoint_step_binary_symmetric(func_name: str, file_name: str, deserial_funcs, type_a, type_b):
    output_file_path = ofp.function_list_path + file_name

    typeA_objectD = False
    typeB_objectD = False
    
    # Requiring type template information
    templ_type = ofp.get_type_template(type_a, ofp.type_path)
    if('ObjectD' in templ_type):
        typeA_objectD = True

    templ_type = ofp.get_type_template(type_b, ofp.type_path)
    if('ObjectD' in templ_type):
        typeB_objectD = True

    functions_parsed = []

    # parsing file
    for f in deserial_funcs:
        if(f['function_declaration']['name_prefix'] == func_name):
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

        
    # identify missing cases: # TODO: outsource
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
        
    ### fixpoint step ###
    change_flag = False

    lam_func_decl = lambda func: func["function_declaration"]["parameters"] # lambda to ease accessing parameter data within filter-function
   
    # iterate over missing cases
    for mc in missing_cases:
        l = []
        
        ### symmetric cases ### TODO: outsource
        list_prefiltered = list(filter(lambda func: (get_type_minus_template(lam_func_decl(func)[0]["type_name"]) == type_b[0]) and (get_type_minus_template(lam_func_decl(func)[1]["type_name"]) == type_a[0]) and (func["function_declaration"]["name_prefix"] == func_name), deserial_funcs)) 
        if not typeA_objectD and not typeB_objectD:
            l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc, list_prefiltered))

        elif typeA_objectD != typeB_objectD: # XOR
            if typeA_objectD:
                l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc[1] and lam_func_decl(func)[0]["object_dim"] == mc[0], list_prefiltered))
            elif typeB_objectD:
                l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc[1] and lam_func_decl(func)[1]["object_dim"] == mc[0], list_prefiltered))
        
        elif typeA_objectD and typeB_objectD:
            l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc[2] and lam_func_decl(func)[0]["object_dim"] == mc[0] and lam_func_decl(func)[1]["object_dim"] == mc[1], list_prefiltered))
        
        if len(l) > 0:
            # taking the first matching symmetric implementation
            new_function = copy.deepcopy(l[0])
            # swap the parameters
            temp_param = lam_func_decl(new_function)[0]
            lam_func_decl(new_function)[0] = lam_func_decl(l[0])[1]
            lam_func_decl(new_function)[1] = temp_param
            new_function["symmetric_implementation"] = True
            # append to deserial funcs
            deserial_funcs.append(new_function)
            # TODO: DEBUG
            change_flag = True # changes appeared - another step is necessary
            continue

        ### check for rules ### # TODO: outsource
        # TODO: Maybe consider more rules (special rulesets)
        # TODO: Check for matching types in rule set
        rules_applicable = list(filter(lambda rule: (rule["implementee"] == func_name) and (rule["type_A"] == "") and (rule["type_B"] == ""), common_rules_sym))

        for rule in rules_applicable:
            if not are_implemented(rule, type_a[0], type_b[0]):
                rules_applicable.remove(rule)
                continue

        if len(rules_applicable) == 0:
            # there are no applicable rules
            continue

        new_function = {} # new func to append to deserial_funcs
        
        # NOTE: format of elements in missing cases may differ -> 4 cases to handle
        if typeA_objectD and typeB_objectD:
            new_function = ofp.generate_function_entry_binary(rules_applicable[0], mc[0], mc[1], mc[2], type_a, type_b)

        elif typeA_objectD:
            new_function = ofp.generate_function_entry_binary(rules_applicable[0], mc[0], "", mc[1], type_a, type_b)
        
        elif typeB_objectD:
            new_function = ofp.generate_function_entry_binary(rules_applicable[0], "", mc[0], mc[1], type_a, type_b)

        else: # not typeA_objectD and not typeB_objectD
            new_function = ofp.generate_function_entry_binary(rules_applicable[0], "", "", mc[0], type_a, type_b)

        deserial_funcs.append(new_function)
        change_flag = True # changes appeared. Another step necessary
        continue



    # write deserial_funcs to file if changes appeared (indicated by 'change flag')
    if change_flag:
        with open(ofp.function_list_path + file_name + '.json', 'w') as f:
            json_object = json.dumps(deserial_funcs, indent = 4)
            f.write(json_object)

    return change_flag


def fixpoint_iteration_step(type):
    change_flag = False
    # unary fixpoint-step -> TODO: Nothin happens here probably
    for func in ofp.unary_functions:
        f = open('function_lists/' + func[1] + ".json")
        deserial_functions = json.load(f) # list format
        if fixpoint_step_unary(func[0], func[1], deserial_functions, type):
            change_flag = True

    # binary symmetric fixpoint-step
    for func in ofp.binary_symmetric_functions:
        f = open('function_lists/' + func[1] + ".json")
        deserial_functions = json.load(f)
        for other_type in ofp.common_types:
            if fixpoint_step_binary_symmetric(func[0], func[1], deserial_functions, type, other_type):
                change_flag = True

    # TODO: binary asymmetric fixpoint-step

    return change_flag


### MAIN ###
it_count = 0
max_iterations = 1 # max number of iterations until iteration stops
change_flag = True # indicate if any changes appeared in current fixpoint step

if not os.path.exists(ofp.function_list_path):
    os.makedirs(ofp.function_list_path)

# DEBUG
time_start = time.time() # in seconds

# Fixpoint iteration running for a max number of steps or until convergence
while change_flag and (it_count < max_iterations):
    change_flag = False
    for type in ofp.all_types:
        if fixpoint_iteration_step(type):
            change_flag = True
    it_count += 1

# DEBUG
time_end = time.time() # in seconds
dif = time_end - time_start # in seconds
print("nbr_iterations: " + str(it_count))
print("duration in seconds:" + str(dif))