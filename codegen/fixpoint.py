import json
import os
import processing as pro


type_path = "../src/typed-geometry/types/"

# fixpoint iteration rulesets
# [function_name, implemented_by function_name, return_statement]
ruleset_intersects = [["intersects", "intersection", "intersection(obja, objb).has_value();"]]

# collection of all rulesets
rulesets = ruleset_intersects

out_path = "typed-geometry/json-files/"

def get_func_name(text: str):
    ind_end = text.index('(')
    ind_start = ind_end

    while text[ind_start] != " ":
        ind_start -= 1
    
    ind_start += 1
    return text[ind_start:ind_end] 

def get_types(text: str):
    ind_start = text.index('(')
    ind_end = pro.index_of_closing(text, ind_start)
    args = text[ind_start+1:ind_end] # args without enclosing brackets

    types = []

    while args:
        if "<" in args:
            start = args.index('<')
            end = pro.index_of_closing(args, start)

            if ',' in args:
                comma = args.index(',')
                if(comma < start):
                    types.append(args.split()[0].strip())
                    args = args[comma:]
                    continue

            types.append(args[:end+1].strip())
            args = args[end+1:]

        else:
            types.append(args.split()[0].strip())

        if ',' in args:
                sep_index = args.index(',')
                args = args[sep_index+1:]
                continue
        
        break
    
    return types


# get information for one specific implementation of a function
# If an argument of the function is not depending on the object information, 'objectDimX' should be empty (i.e. "")
def get_impl_info(lines, start_ind: int, end_ind: int, object_dim_dep: bool, binary: bool):
    impl_info = {}
    line = lines[start_ind].strip()

    domainDim = ""
    objectDimA = ""
    objectDimB = ""
    impl = ""

    if line.startswith("return"):
        if(object_dim_dep):
            objectDimA = 'O'

        domainDim = 'D'

    if line.startswith("if"):
        # get domain and possibly object dimensional information
        if "O == D" in line:
            domainDim = 'D'
            objectDimA = 'D'

        else:
            if "D" in line:
                domainDim = line[line.index('D') + 5]
            if "O" in line:
                objectDimA = line[line.index('O') + 5]
    
    else:
        if line.startswith("else"):
            domainDim = 'D'

            if object_dim_dep:
                objectDimA = 'O'
            else:
                objectDimA = ''

    if object_dim_dep and objectDimA == "":
        objectDimA = domainDim

    start_ind += 2

    while start_ind < end_ind:
        curr_line = lines[start_ind].strip()
        
        if binary:
            if curr_line.startswith("return"):
                start_args = curr_line.index('(')
                if(curr_line[start_args-3:start_args-2] == "in"): # object domain info
                    objectDimB = curr_line[start_args-4]

        # store implementation body in "impl"
        impl += lines[start_ind].strip() + "\n "

        # TODO: Might be possible to perform this check before computing dimensional information for reduction of overhead
        if impl.startswith("static_assert"): # do not store non-impl message
            return {}
        
        start_ind += 1

    # storing informtion in object
    impl_info["objectDimA"] = objectDimA
    impl_info["objectDimB"] = objectDimB
    impl_info["domainDim"] = domainDim
    impl_info["impl"] = impl

    return impl_info


# NOTE: adapted parser: parse files and search for non-implemented function. If found any -> check in ruleset if can be implemented via other function
def fixpoint_step(text: str):
    # TODO
    lines = text.split("\n")
    return


# NOTE: intermediate parser: parse given file (text) and store some relevant information for the contained functions and their implementations in .json format
def parse_function_file(text: str, output_file: str):
    # separate into lines
    lines = text.split("\n")

    typeA_objectD = False

    type_info = lines[4]
    if "O" in type_info:
        typeA_objectD = True

    function_decls = [] # storing all function information (list of json objects)
    line_index = 0

    while line_index < (len(lines) - 2):
        line = lines[line_index]
        line = line.strip()

        if(line.startswith("static constexpr")): # found new function declaration
            curr_function_decl = {} # json object
            curr_function_decl["func_name"] = get_func_name(line)
            curr_function_decl["line_nbr"] = line_index
            types = get_types(line)
            curr_function_decl["types"] = types
            implementations = [] # store implementation infos

            binary = False
            if len(types) > 1: # binary function
                binary = True
                
            line_temp_ind = line_index + 1

            # while not found the end of the function declaration
            while not (lines[line_temp_ind].strip().startswith("}") and (lines[line_temp_ind + 2].strip().startswith("static constexpr") or lines[line_temp_ind + 2].strip().startswith("};"))): # found end of function
                line_temp = lines[line_temp_ind].strip()
                
                # found an implementation or static assert case -> begin of scope
                if line_temp.startswith("if") or line_temp.startswith("else"):
                    start_impl = line_temp_ind

                    # looking for end of scope
                    while not lines[line_temp_ind].strip().startswith("}"):
                        line_temp_ind += 1

                    impl_info = get_impl_info(lines, start_impl, line_temp_ind, typeA_objectD, binary)

                    # only store if not the static non-impl message
                    if len(impl_info) > 0:
                        implementations.append(impl_info)
                    continue
                
                else:
                    # found direct return statement in declaration scope -> only one implementation
                    if line_temp.startswith("return"):
                        impl_info = get_impl_info(lines, line_temp_ind-2, line_temp_ind+1, typeA_objectD, binary)
                        implementations.append(impl_info)
                    
                line_temp_ind += 1

            
            line_index = line_temp_ind

            curr_function_decl["implementations"] = implementations
            function_decls.append(curr_function_decl)
            line_index += 1

            continue

        if(line.startswith("static_assert")): # found missing impl
            line_prev = lines[line_index - 1]
            # TODO: get domain info for missing case from line_prev
            

        line_index += 1

    # write to file
    with open(out_path + output_file + '.json', 'w') as f:
        json_object = json.dumps(function_decls, indent = 4)
        f.write(json_object)

    return


### MAIN ###
if not os.path.exists(out_path):
    os.makedirs(out_path)

# TODO fixpoint-iteration till convergence
changes = False

for f in os.listdir("typed-geometry/object-functions/"):
    in_file = "typed-geometry/object-functions/" + f #+ '.hh'
    text = open(in_file, "r").read()
    parse_function_file(text, f[:-3])