import json
import os
import processing as pro

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
    return text[ind_start:ind_end-1] 

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
                    types.append(args.split()[0])
                    args = args[comma:]
                    continue

            types.append(args[:end+1])
            args = args[end+1:]

        else:
            types.append(args.split()[0])

        if ',' in args:
                sep_index = args.index(',')
                args = args[sep_index+1:]
                continue
        
        break
    
    return types


# adapted parser -> parse files and search for non-implemented function. If found any -> check in ruleset if can be implemented via other function
def parse_function_file(text: str, output_file: str):
    # separate into lines
    lines = text.split("\n")
    
    function_decls = []
    line_index = 0

    while line_index < len(lines):
        line = lines[line_index]
        line = line.strip()

        if(line.startswith("static constexpr")):
            # found new function -> context info
            curr_function_decl = {}
            curr_function_decl["func_name"] = get_func_name(line)
            curr_function_decl["line_nbr"] = line_index
            curr_function_decl["types"] = get_types(line)

            # TODO: searching till end of the function and store domain and impl infos for function implementations
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

# TODO outer_loop till convergence
changes = False

for f in os.listdir("typed-geometry/object-functions/"):
    in_file = "typed-geometry/object-functions/" + f #+ '.hh'
    text = open(in_file, "r").read()
    parse_function_file(text, f[:-3])

