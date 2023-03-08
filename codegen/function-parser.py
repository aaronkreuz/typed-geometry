import json
import os
import processing as ofp

# Dump function declarations of function files (renamed files) in json objects and store in '"function".json'

#in_file = "../src/typed-geometry/functions/objects/aabb.hh"
in_path = "renamed_files/"
out_path = "function_lists/"

# files = [
#     "area",
#     "closest_points",
#     "contains",
#     "distance",
#     "intersection",
#     "project",
#     "any_point",
#     "aabb",
#     "triangulate",
#     "triangulation"
# ]

def read_type(s: str):
    if "<" in s:
        closing_index = ofp.index_of_closing(s, s.index("<"))
        if "," in s:
            comma = s.index(',')
            if(comma < s.index('<')):
                return s.split()[0]
        return s[:(closing_index + 1)]
    return s.split()[0]


def parse_template_parameters(s: str):
    start = s.index("<")
    end = ofp.index_of_closing(s, start)
    params = s[start + 1:end].split(",")

    #print(params)
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

    #print(params)

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


def get_domain_dim(s :str):
    try:
        start_template = s.index("<")
        end_template = ofp.index_of_closing(s, start_template)
        s = s[start_template+1:end_template]
        l = s.split(',')
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

def get_object_dim(s :str):
    try:
        start_template = s.index("<")
        end_template = ofp.index_of_closing(s, start_template)
        s = s[start_template+1:end_template]
        l = s.split(',')
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
    parsed_function["name"] = function_name
    parsed_function["parameters"] = function_parameters
    parsed_function["return_type"] = return_type

    return parsed_function

def collect_functions(text: str, output_file: str):
    lines = text.split('\n')

    functions = []

    line_index = 0
    while line_index < len(lines):
        line = lines[line_index]

        line = line.strip()

        if line == "":
            line_index += 1
            continue

        if line.startswith("[[nodiscard]] constexpr"): # function found
            template_declaration = lines[line_index-1]

            # check if templated function
            try:
                x = template_declaration.index('<')
            except ValueError as ve:
                line_index += 1
                continue

            function_declaration = line
            print(str(line_index) + " " + function_declaration)

            # function declaration over multiple lines
            while lines[line_index+1].strip() != "{":
                function_declaration += lines[line_index+1]
                function_declaration = function_declaration.strip()
                line_index += 1

            # collect the function body
            body_start = line_index + 2
            body_end = line_index + 2
            while lines[body_end].strip() != "}":
                body_end += 1

            body = ""
            for i in range(body_start, body_end):
                body += lines[i] + "\n"
            line_index = body_end

            # build up JSON object for each function consisting of template parameters, function decl. and body
            function = {}
            function["template-parameters"] = parse_template_parameters(
                template_declaration)
            function["function_declaration"] = parse_function_declaration(
                function_declaration)
            function["body"] = body.strip()

            functions.append(function)

        line_index += 1

    # write to file
    with open(out_path + output_file + '.json', 'w') as f:
        json_object = json.dumps(functions, indent = 4)
        f.write(json_object)

### MAIN APP ###
#for file in files:
for file in os.listdir(in_path):
    in_file = in_path + file #+ '.hh'
    text = open(in_file, "r").read()
    collect_functions(text, file[:-3])

