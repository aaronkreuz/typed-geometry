import json
import os
import processing as ofp

def read_type(type_decl: str):
    if "<" in type_decl:
        closing_index = ofp.index_of_closing(type_decl, type_decl.index("<"))
        if "," in type_decl:
            comma = type_decl.index(',')
            if(comma < type_decl.index('<')):
                return type_decl.split()[0]
        return type_decl[:(closing_index + 1)]
    return type_decl.split()[0]


def parse_template_parameters(type_decl: str):
    start = type_decl.index("<")
    end = ofp.index_of_closing(type_decl, start)
    params = type_decl[start + 1:end].split(",")

    # TODO preprocessing template args
    it = 0
    while(it < len(params)):
        if(params[it].startswith(" typename") or params[it].startswith(" std::enable_if_t")):
            params_temp = "".join(params[it:])
            idx_end = ofp.index_of_closing(params_temp, params_temp.index("<"))
            params_append = params_temp[idx_end + 1:].split(",")
            #print(params_append)
            params = params[:it] + [params_temp[:idx_end+1].strip()]
            if not params_append[0] == '':
                params += params_append

        it += 1
            # params = [params[0], "".join(params[1:])]

    parsed_params = []
    for p in params:
        p = p.strip()
        pp = p.split(maxsplit=1) #separate typename from variable_name and default_value

        typename = pp[0]
        # check for unnamed var
        # if(pp[1] == '='):
        #     variable_name = ""
        #else:
        variable_name = pp[1]

        default_value = ""
        if "=" in variable_name:
            variable_name, default_value = variable_name.split("=")
        variable_name = variable_name.strip()
        default_value = default_value.strip()
        parsed_params.append(
            {"typename": typename, "variable_name": variable_name, "default_value": default_value})
    return parsed_params


def get_domain_dim(type_decl :str):
    try:
        start_template = type_decl.index("<")
        end_template = ofp.index_of_closing(type_decl, start_template)
        type_decl = type_decl[start_template+1:end_template]
        l = type_decl.split(',')
        l = [e.strip() for e in l]

        filtered_list = filter(lambda a: (a == "DomainD" or a == "D" or a == "1" or a == "2" or a == "3" or a == "4"), l)
        l = list(filtered_list)

        if len(l) == 1:
            ret = "D" if l[0] == "DomainD" else l[0]
            return ret

        if len(l) == 2:
            ret = "D" if l[1] == "ObjectD" else l[1]
            return ret

    except ValueError as ve:
        return ""
    
    return ""


def get_object_dim(type_decl :str):
    try:
        start_template = type_decl.index("<")
        end_template = ofp.index_of_closing(type_decl, start_template)
        type_decl = type_decl[start_template+1:end_template]
        l = type_decl.split(',')
        l = [e.strip() for e in l]

        filtered_list = filter(lambda a: (a == "ObjectD" or a == "D" or a == "O" or a == "1" or a == "2" or a == "3" or a == "4"), l)

        l = list(filtered_list)
        if(len(l) >= 1):
            ret = "O" if l[0] == "ObjectD" else l[0]
            return ret # in case of no deviation of objectDim and domainDim this will just return the domainDim which is intended
        else:
            return ""
    except ValueError as ve:
        return ""


def parse_function_declaration(s: str):
    modifyers = []
    if s.startswith("[[nodiscard]]"):
        modifyers.append("[[nodiscard]]")
        s = s[len("[[nodiscard]]"):]
        s = s.strip()

    if s.startswith("constexpr"):
        modifyers.append("constexpr")
        s = s[len("constexpr"):]
        s = s.strip()

    end_idx = s.index("(")
    return_type_and_function_name = s[:end_idx].split()
    function_name = return_type_and_function_name[-1]
    return_type = "".join(return_type_and_function_name[:-1])
    s = s[(1+end_idx):]

    # function parameters
    closing_index = s.index(")")
    function_parameters_raw = s[:closing_index]
    function_parameters = []

    while function_parameters_raw:
        type_name = read_type(function_parameters_raw)

        function_parameters_raw = function_parameters_raw[len(
            type_name):].strip()

        if function_parameters_raw.startswith("const"):
            type_name += " " + "const"
            function_parameters_raw = function_parameters_raw[len(
                "const"):].strip()

        if function_parameters_raw.startswith("&"):
            type_name += "&"
            function_parameters_raw = function_parameters_raw[len(
                "&"):].strip()

        if function_parameters_raw.startswith("..."):
            type_name += "..."
            function_parameters_raw = function_parameters_raw[len(
                "..."):].strip()

        parameter_rest = function_parameters_raw.split()
        parameter_name = ""

        if not len(parameter_rest) == 0:
            if not parameter_rest[0].startswith(","):
                    parameter_name = parameter_rest[0]

            
        function_parameters_raw = function_parameters_raw[len(parameter_name):]
        function_parameters_raw = function_parameters_raw.strip()

        default_value = ""
        if function_parameters_raw.startswith("="):
            round_brackets_level = 0
            square_brackets_level = 0
            curly_brackets_level = 0
            angle_brackets_level = 0
            function_parameters_raw = function_parameters_raw[1:].strip()
            offset = 0
            for char in function_parameters_raw:
                if char == "{":
                    curly_brackets_level += 1
                if char == "}":
                    curly_brackets_level -= 1
                if char == "[":
                    square_brackets_level += 1
                if char == "]":
                    square_brackets_level -= 1
                if char == "<":
                    angle_brackets_level += 1
                if char == ">":
                    angle_brackets_level -= 1
                if char == "(":
                    round_brackets_level += 1
                if char == ")":
                    round_brackets_level -= 1
                if char == ",":
                    if curly_brackets_level == 0 and square_brackets_level == 0 and angle_brackets_level == 0 and round_brackets_level == 0:
                        break
                offset += 1
            
            default_value = function_parameters_raw[:offset]
            function_parameters_raw = function_parameters_raw[(offset + 1):].strip()


        if function_parameters_raw.startswith(","):
            function_parameters_raw = function_parameters_raw[1:].strip()
        function_parameters.append(
            {"type_name": type_name, "parameter_name": parameter_name, "default_value": default_value, "domain_dim": get_domain_dim(type_name), "object_dim": get_object_dim(type_name)})

    s = s[(closing_index + 1):]
    s = s.strip()

    if return_type == "auto":
        if (s.startswith("->")):
            s = s[2:]
            s = s.strip()
            return_type = s
        else:
            return_type = 'auto'

    parsed_function = {}
    parsed_function["modyfiers"] = modifyers
    parsed_function["name_prefix"] = function_name
    parsed_function["parameters"] = function_parameters
    parsed_function["return_type"] = return_type

    return parsed_function

def get_new_func_name(function_declaration):
    function_name = function_declaration["name_prefix"]
    params = function_declaration["parameters"]

    # only change functions listed in "functions"
    if(not function_name in ofp.functions):
        return function_name

    new_funcname = function_name

    for arg in params:
        type_name = arg["type_name"]

        if not "const&" in type_name:
            continue

        type_name = read_type(arg["type_name"])

        if "<" in type_name:
            type_name = type_name[:type_name.index("<")]

        object_dim = arg["object_dim"]
        domain_dim = arg["domain_dim"]

        if domain_dim == "DomainD":
            domain_dim = "D"

        if not (object_dim == domain_dim) and not (object_dim == 'D'):
            new_funcname += "_" + type_name + object_dim + "in" + domain_dim
        else:
            if not domain_dim == 'D':
                new_funcname += "_" + type_name + domain_dim
            else:
                new_funcname += "_" + type_name
    
    return new_funcname

# replace old function name by new name in a given function declaration line
def replace_func_name_in_line(line: str, new_func_name: str, old_func_name: str):
    start_func_name = line.find(old_func_name)

    first_part = line[:start_func_name]
    last_part = line[start_func_name + len(old_func_name):]

    return first_part + new_func_name + last_part


# rename functions and store in json objects at the same time
def parse_functions(text: str, output_file: str):
    lines = text.split('\n')

    functions = []
    new_lines = []

    line_index = 0
    while line_index < len(lines):
        line = lines[line_index].strip() + '\n'

        if line.startswith("[[nodiscard]] constexpr"): # function found
            template_declaration = lines[line_index-1]
            temp_line_index = line_index

            # check if templated function
            try:
                x = template_declaration.index('<')
            except ValueError as ve:
                line_index += 1
                new_lines.append(line)
                continue

            function_declaration = line
            # function declaration over multiple lines
            while lines[temp_line_index+1].strip() != "{":
                function_declaration += lines[temp_line_index+1]
                function_declaration = function_declaration.strip()
                temp_line_index += 1

            # collect the function body
            body_start = temp_line_index + 2
            body_end = temp_line_index + 2
            while lines[body_end].strip() != "}":
                body_end += 1

            body = ""
            for i in range(body_start, body_end):
                body += lines[i] + "\n"
            temp_line_index = body_end

            # build up JSON object for each function consisting of template parameters, function decl. and body
            function = {}
            function["template-parameters"] = parse_template_parameters(
                template_declaration)
            function["function_declaration"] = parse_function_declaration(
                function_declaration)
            function["body"] = body.strip()
            function["symmetric_implementation"] = False

            # rename_function
            new_func_name = get_new_func_name(function["function_declaration"])

            function["function_declaration"]["name"] = new_func_name
            functions.append(function)

            new_line = replace_func_name_in_line(line, new_func_name,  function["function_declaration"]["name_prefix"])
            new_lines.append(new_line)

            # catch up till end of the current parsed function
            while(line_index < temp_line_index):
                line_index += 1
                line = lines[line_index] + '\n'
                new_lines.append(line)

        else:
            new_lines.append(line)

        line_index += 1

    # TODO: Should overwrite the source files
    # write renamed functions to file
    with open(ofp.renamed_files_path + output_file + '.hh', 'w') as f:
        f.writelines(new_lines)

    # return json dump
    return functions #json.dumps(functions, indent = 4)    

    # write to file json dumps
    with open(ofp.function_list_path + output_file + '.json', 'w') as f:
        json_object = json.dumps(functions, indent = 4)
        f.write(json_object)




### MAIN APP ### NOTE: Functionality outsourced to main_pipeline.py!
# if not os.path.exists(ofp.renamed_files_path):
#     os.makedirs(ofp.renamed_files_path)
# 
# if not os.path.exists(ofp.function_list_path):
#     os.makedirs(ofp.function_list_path)
# 
# for file in ofp.function_files:
#     in_file = ofp.src_function_path + file
#     text = open(in_file, "r").read()
#     parse_functions(text, file[:-3])