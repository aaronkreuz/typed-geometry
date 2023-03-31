import os
import json
import numpy as np
import processing as ofp
import object_type as ot
import copy
import time # temporary

# load common rules from file
# TODO: there can also be rules that are only applicable for specific type of functions
r = open(ofp.rules_path + "common_rules_binary" + ".json") 
common_rules_sym = json.load(r) # list format


# NOTE: There does not seem to be any rule for unary functions being applied by another function -> This case might be ignored
def fixpoint_unary(func_name: str, file_name: str, deserial_funcs, type: ot.geo_type):
    output_file_path = ofp.function_list_path + file_name

    functions_parsed = []

    # parsing file
    for f in deserial_funcs:
        func = ofp.parse_function_info_unary(f, func_name, type.get_name())
        if len(func) > 0:
            functions_parsed.append(func)
    
    # check if an implementation is missing -> requires info if type is object-dim.-dependent
    found_domains = []

    for func in functions_parsed:
        domD = func['domain_dim']
        objD = func['object_dim']
        if type.is_obj_dim_dependent():
            found_domains.append((objD, domD))
        else:
            found_domains.append(domD)

    # identify missing cases:
    if ("O","D") in found_domains or "D" in found_domains: # does this work?
        return False # all cases handled
    
    # missing cases in varying format -> TODO: missing cases as data type to obtain consistent representation
    missing_cases = []
    
    if type.is_obj_dim_dependent():
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


# NOTE: Checks if pre-conditions for rule application are fulfilled (i.e. necessary functions implemented)
def are_implemented(rule, type_a: str, type_b: str, domainD: str, objectD_a: str, objectD_b: str):
    new_impl = rule["implementation"][:] # copy

    # iterating over implementers that have to be implemented
    for impl in rule["implementer"]:
        params = impl["param_types"][:] # copy
        # open corresponding file by looking up table
        funcs = list(filter(lambda func: func[0] == impl["func_name"], ofp.all_functions))

        if len(funcs) == 0: # should not happen
            return ""
        
        func_found = funcs[0]
        # open the corresponding json file from "function_lists"
        f = open(ofp.function_list_path + func_found[1] + ".json", "r")
        funcs_implementer = json.load(f) # list format

        func_param = lambda func: func["function_declaration"]["parameters"]

        # filtering function file for correct func name
        filtered_funcs = list(filter(lambda func: (func["function_declaration"]["name_prefix"] == func_found[0]), funcs_implementer))

        # checking for params
        param_counter = 0
        for param in params:
            objectDimToTest = ""
            domainDimToTest = ""

            # special cases: # TODO: More special cases might arise!
            try:
                # ScalarT
                if "ScalarT" in params:
                    filtered_funcs = list(filter(lambda func: params in func_param(func)[param_counter], filtered_funcs))
                    continue
                
                # solid_of()
                if "solid_of" in param:
                    if "AAA" in param:
                        param = type_a[:]
                    elif "BBB" in param:
                        param = type_b[:]
                    if "_boundary" in param:
                        param.replace() #???

                if "AAA" in param:
                    param = param.replace("AAA", type_a)
                    domainDimToTest = domainD
                    objectDimToTest = objectD_a
                if "BBB" in param:
                    param = param.replace("BBB", type_b)
                    domainDimToTest = domainD
                    objectDimToTest = objectD_b

                # TODO: What if parameter is not AAA or BBB and neither of the above but the result of an previous function
                # -> should also be handled within the following filters

                filtered_funcs = list(filter(lambda func: get_type_minus_template(func_param(func)[param_counter]["type_name"]) == param or ((param.startswith(get_type_minus_template(func_param(func)[0]["type_name"]))) and ("boundary" in param) and ("TraitsT" in func_param(func)[0]["type_name"])), filtered_funcs))

                if(objectDimToTest != "" and domainDimToTest != ""):
                    filtered_funcs = list(filter(lambda func: (func_param(func)[param_counter]["domain_dim"] == domainDimToTest) or (func_param(func)[param_counter]["domain_dim"] == "D"), filtered_funcs))
                    filtered_funcs = list(filter(lambda func: (func_param(func)[param_counter]["object_dim"] == objectDimToTest) or ((func_param(func)[param_counter]["object_dim"] == "D") and (objectDimToTest == domainDimToTest)) or (func_param(func)[param_counter]["object_dim"] == "O"), filtered_funcs))
                else:
                    # Dimensional infomation missing:
                    print("[fixpoint-experimental]: Missing dimensional information for filtering in 'are_implemented'")
                
            except ValueError as ve:
                # TODO: shouldn't this be an error case where rule can't be applied??
                param_counter += 1
                continue

            param_counter += 1

            # filtered_funcs = list(filter(lambda func: get_type_minus_template(func_param(func)[0]["type_name"]) == type_a or ((type_a.startswith(get_type_minus_template(func_param(func)[0]["type_name"]))) and ("boundary" in type_a) and ("TraitsT" in func_param(func)[0]["type_name"])), filtered_funcs))
            # if type_b != "": # binary func
            #     filtered_funcs = list(filter(lambda func: get_type_minus_template(func_param(func)[1]["type_name"]) == type_b or ((type_b.startswith(get_type_minus_template(func_param(func)[1]["type_name"]))) and ("boundary" in type_b) and ("TraitsT" in func_param(func)[1]["type_name"])), filtered_funcs))

        # Check if filtered functions do not have more parameters than expected
        filtered_funcs = list(filter(lambda func: len(func_param(func)) == len(params), filtered_funcs))
            
        # filtering for return type if necessary
        if impl["return_type"] != "":
            filtered_funcs = list(filter(lambda func: impl["return_type"] in func["return_type"], filtered_funcs))

        if len(filtered_funcs) == 0: # implementation missing, can't apply rule
            return ""
        
        # DEBUG
        print("found " + str(len(filtered_funcs)) + " applicable functions")
        
        # change implementation
        func = filtered_funcs[0]
        if func["function_declaration"]["name"] == "": # rule-generated -> copy impl
            # build up lambda function
            lambda_func = "auto " + impl["func_name"] + "[]" + "("
            param_counter = 0
            for param in impl["param_types"]:
                lambda_func += func["function_declaration"]["parameters"][param_counter]["type_name"] + " " + func["function_declaration"]["parameters"][param_counter]["parameter_name"] + ","
                param_counter += 1
            lambda_func = lambda_func[:-1]
            lambda_func += ")" + "{" + '\n'
            lambda_func += func["body"]
            lambda_func += "};"
            # prepend lambda func to 'new_impl'
            new_impl = lambda_func + new_impl

        # TODO: elif symmetric implementation

        else: # real implementation exists -> rename the function in the implementation of the rule
            real_name = func["function_declaration"]["name"]
            # start_name = new_impl.find(impl["func_name"])
            new_impl = new_impl.replace(impl["func_name"], real_name, 1)

    return new_impl


def get_missing_cases_binary(typeA_objectD: bool, typeB_objectD: bool, found_domains):
    missing_cases = []

    valid_domain_values = ["1", "2", "3"] # TODO: What about D?

    # Case 1: both types have object dim varying from domain dim
    if typeA_objectD and typeB_objectD:

        for objA_i in valid_domain_values:
            for objB_i in valid_domain_values:

                if (objA_i, objB_i, "D") in found_domains:
                    continue # case handled

                dom_i = str(max(int(objA_i), int(objB_i)))
                while int(dom_i) <= 3:
                    if not (objA_i, objB_i, dom_i) in found_domains:
                        missing_cases.append((objA_i, objB_i, dom_i))
                    dom_i = str(int(dom_i)+1)
    
    # Case 2: only one type has object dim varying from domain dim
    if (typeA_objectD and not typeB_objectD) or (typeB_objectD and not typeA_objectD):
        for obj_i in valid_domain_values: # TODO: are this all possible obj. dims?
            if (obj_i,"D") in found_domains:
                continue
            
            dom_i = obj_i
            while int(dom_i) <= (int(obj_i) + 1): # TODO: Maybe instead of "(int(obj_i)+1)" just "3" as above
                if not (obj_i, dom_i) in found_domains:
                    missing_cases.append((obj_i, dom_i))
                dom_i = str(int(dom_i) + 1)

    # Case 3: none of the types has object dim varying from domain dim
    if not typeA_objectD and not typeB_objectD:
        if "D" in found_domains:
            return [] # all cases handled
        for dom_i in valid_domain_values:
            if not dom_i in found_domains:
                missing_cases.append(dom_i)

    return missing_cases


def fixpoint_binary_symmetric(func_name: str, file_name: str, deserial_funcs, type_a: ot.geo_type, type_b: ot.geo_type):
    output_file_path = ofp.function_list_path + file_name

    functions_parsed = []

    # parsing file
    for f in deserial_funcs:
        if(f['function_declaration']['name_prefix'] == func_name):
            # checking for matching parameters and store relevant information
            func = ofp.parse_function_info_binary_symmetric(f, func_name, type_a.get_name(), type_b.get_name())
            if len(func) > 0:
                functions_parsed.append(func)
    
    # check if an implementation is missing -> requires info if type is object-dim.-dependent
    found_domains = [] # TODO: Could probably be stored in instance of same data type as missing cases

    # store domain combinations that are handled
    for func in functions_parsed:
        function_paramsA = func['params'][0]
        function_paramsB = func['params'][1]
        domD = function_paramsA['domain_dim'] # domain dimension equal for type A and B
        objD_A = function_paramsA['object_dim']
        objD_B = function_paramsB['object_dim']

        if type_a.is_obj_dim_dependent() and type_b.is_obj_dim_dependent():
            found_domains.append((objD_A, objD_B, domD))
            continue
        
        if type_a.is_obj_dim_dependent() and not type_b.is_obj_dim_dependent():
            found_domains.append((objD_A, domD))
            continue

        if not type_a.is_obj_dim_dependent() and type_b.is_obj_dim_dependent():
            found_domains.append((objD_B, domD))
            continue

        else: # A not ODD and B not ODD (Object Domanin Dependent)
            found_domains.append(domD)

        
    # identify missing cases: # TODO: outsource
    if ("O","O","D") in found_domains or ("O","D") in found_domains or "D" in found_domains: # does this work?
        return # all cases handled
    
    missing_cases = get_missing_cases_binary(type_a.is_obj_dim_dependent(), type_b.is_obj_dim_dependent(), found_domains)

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
        list_prefiltered = list(filter(lambda func: (get_type_minus_template(lam_func_decl(func)[0]["type_name"]) == type_b.get_name()) and (get_type_minus_template(lam_func_decl(func)[1]["type_name"]) == type_a.get_name()) and (func["function_declaration"]["name_prefix"] == func_name), deserial_funcs)) 
        if not type_a.is_obj_dim_dependent() and not type_b.is_obj_dim_dependent():
            l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc, list_prefiltered))

        elif type_a.is_obj_dim_dependent():
            l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc[1] and lam_func_decl(func)[0]["object_dim"] == mc[0], list_prefiltered))

        elif type_b.is_obj_dim_dependent():
            l = list(filter(lambda func: lam_func_decl(func)[0]["domain_dim"] == mc[1] and lam_func_decl(func)[1]["object_dim"] == mc[0], list_prefiltered))
        
        else: # typeA_objectD and typeB_objectD
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
        rules_applicable = list(filter(lambda rule: (rule["implementee"] == func_name), common_rules_sym))
        # checking for matching typeA (including boundary_tag check)
        rules_applicable = list(filter(lambda rule: (rule["type_A"] == "") or type_a.get_name().startswith(rule["type_A"]) and ((rule["type_A_boundary_tag"] == "") or ((rule["type_A_boundary_tag"] == "required") and "boundary" in type_a.get_name())), rules_applicable))
        # checking for matching typeB (including boundary_tag check)
        rules_applicable = list(filter(lambda rule: (rule["type_B"] == "") or type_b.get_name().startswith(rule["type_B"]) and ((rule["type_B_boundary_tag"] == "") or ((rule["type_B_boundary_tag"] == "required") and "boundary" in type_b.get_name())), rules_applicable))

        new_rule_impl = ""
        rules_applicable_temp = rules_applicable.copy()
        for rule in rules_applicable_temp:
            # check if rule pre-conditions are implemented ; TODO: Check also for dimensionalities
            if type_a.is_obj_dim_dependent() and type_b.is_obj_dim_dependent():
                new_rule_impl = are_implemented(rule, type_a.get_name(), type_b.get_name(), mc[2], mc[0], mc[1])

            elif type_a.is_obj_dim_dependent():
                new_rule_impl = are_implemented(rule, type_a.get_name(), type_b.get_name(), mc[1], mc[0], mc[1])

            elif type_b.is_obj_dim_dependent():
                new_rule_impl = are_implemented(rule, type_a.get_name(), type_b.get_name(), mc[1], mc[1], mc[0])

            else: # not typeA_objectD and not typeB_objectD
                new_rule_impl = are_implemented(rule, type_a.get_name(), type_b.get_name(), mc[0], mc[0], mc[0])
                
            if new_rule_impl == "":
                rules_applicable.remove(rule)
                continue
            else:
                break

        if len(rules_applicable) == 0:
            # there are no applicable rules
            continue

        new_function = {} # new func to append to deserial_funcs
        rule_to_be_applied = copy.deepcopy(rules_applicable[0]) # will be modified
        rule_to_be_applied["implementation"] = new_rule_impl

        # NOTE: format of elements in missing cases may differ -> 4 cases to handle
        if type_a.is_obj_dim_dependent() and type_b.is_obj_dim_dependent():
            new_function = ofp.generate_function_entry_binary(rule_to_be_applied, mc[0], mc[1], mc[2], type_a, type_b)

        elif type_a.is_obj_dim_dependent():
            new_function = ofp.generate_function_entry_binary(rule_to_be_applied, mc[0], "", mc[1], type_a, type_b)
        
        elif type_b.is_obj_dim_dependent():
            new_function = ofp.generate_function_entry_binary(rule_to_be_applied, "", mc[0], mc[1], type_a, type_b)

        else: # not typeA_objectD and not typeB_objectD
            new_function = ofp.generate_function_entry_binary(rule_to_be_applied, "", "", mc[0], type_a, type_b)


        deserial_funcs.append(new_function)
        change_flag = True # changes appeared. Another step necessary
        continue

    # write deserial_funcs to file if changes appeared (indicated by 'change flag')
    # if change_flag:
    #     with open(ofp.function_list_path + file_name + '.json', 'w') as f:
    #         json_object = json.dumps(deserial_funcs, indent = 4)
    #         f.write(json_object)

    return change_flag


# def fixpoint_iteration_step(type):
#     change_flag = False
#     # unary fixpoint-step -> TODO: Nothin happens here probably
#     for func in ofp.unary_functions:
#         f = open('function_lists/' + func[1] + ".json")
#         deserial_functions = json.load(f) # list format
#         if fixpoint_unary(func[0], func[1], deserial_functions, type):
#             change_flag = True
# 
#     # binary symmetric fixpoint-step
#     for func in ofp.binary_symmetric_functions:
#         f = open('function_lists/' + func[1] + ".json")
#         deserial_functions = json.load(f)
#         for other_type in ofp.common_types:
#             if fixpoint_binary_symmetric(func[0], func[1], deserial_functions, type, other_type):
#                 change_flag = True
# 
#     # TODO: binary asymmetric fixpoint-step
# 
#     return change_flag

# fixpoint iteration for unary func
def fixpoint_iteration_step_unary(parsed_files):
    change_flag = False

    for func in ofp.unary_functions:
        #f = open('function_lists/' + func[1] + ".json")
        deserial_funcs = parsed_files[func[1]+".hh"]
        # deserial_funcs = json.load(f) # list format

        for type in ofp.all_types:
            # build type object
            type_obj  = ot.geo_type(type[0], type[1])
            type_obj.find_templateForm()
            if fixpoint_unary(func[0], func[1], deserial_funcs, type_obj):
                change_flag = True
                f = deserial_funcs # update parsed files

    change_flag = True

def fixpoint_iteration_step_binary_symmetric(parsed_files):
    change_flag = False

    for func in ofp.binary_symmetric_functions:
        #f = open('function_lists/' + func[1] + ".json")
        deserial_funcs = parsed_files[func[1]+".hh"]

        #deserial_funcs = json.load(f) # list format

        for type in ofp.all_types:
            for other_type in ofp.all_types:
                # build type objects
                type_a_obj = ot.geo_type(type[0], type[1])
                type_b_obj = ot.geo_type(other_type[0], other_type[1])

                type_a_obj.find_templateForm()
                type_b_obj.find_templateForm()

                if fixpoint_binary_symmetric(func[0], func[1], deserial_funcs, type_a_obj, type_b_obj):
                    change_flag = True
                    f = deserial_funcs # update parsed files

    return change_flag

def fixpoint_iteration_step_binary_asymmetric(parsed_files):
    change_flag = False

    for func in ofp.binary_asymmetric_functions:
        #f = open('function_lists/' + func[1] + ".json")
        deserial_funcs = parsed_files[func[1]+".hh"]
        # deserial_funcs = json.load(f) # list format

        for type in ofp.all_types:
            continue

        # TODO binary asymmetric fixpoint-step

    return change_flag


# ### MAIN ### NOTE: Functionality outsourced to main_pipeline.py!
# it_count = 0
# max_iterations = 1 # max number of iterations until iteration stops
# change_flag = True # indicate if any changes appeared in current fixpoint step
# 
# if not os.path.exists(ofp.function_list_path):
#     os.makedirs(ofp.function_list_path)
# 
# # DEBUG
# time_start = time.time() # in seconds
# 
# # Fixpoint iteration running for a max number of steps or until convergence
# # while change_flag and (it_count < max_iterations):
# #     change_flag = False
# #     for type in ofp.all_types:
# #         if fixpoint_iteration_step(type):
# #             change_flag = True
# #     it_count += 1
# 
# while change_flag and (it_count < max_iterations):
#     # DEBUG
#     print ("iteration: " + str(it_count + 1))
# 
#     change_flag = False
# 
#     change_flag = True if fixpoint_iteration_step_unary() else change_flag
# 
#     change_flag = True if fixpoint_iteration_step_binary_symmetric() else change_flag
# 
#     change_flag = True if fixpoint_iteration_step_binary_asymmetric() else change_flag
# 
#     it_count += 1
# 
# 
# # DEBUG
# time_end = time.time() # in seconds
# dif = time_end - time_start # in seconds
# print("nbr_iterations: " + str(it_count))
# print("duration in seconds:" + str(dif))