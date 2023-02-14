import os

src_path = "../src/typed-geometry/functions/objects/"
# in_file = "../src/typed-geometry/functions/objects/distance.hh"
out_file = "renamed_files/"

# text contains content of specified file
#text = open(in_file, "r").read()
# text = f.read()

# functions in these files will be renamed
function_files = [
    "area.hh",
    "centroid.hh",
    "vertices.hh",
    "edges.hh",
    "boundary.hh",
    "closest_points.hh",
    "contains.hh",
    "distance.hh",
    "intersection.hh",
    "project.hh",
    "any_point.hh",
    "aabb.hh",
    "triangulate.hh",
    "triangulation.hh",
    "rasterize.hh",
    "volume.hh",
    "faces.hh",
]

# only these functions will be renamed
functions = [
    "edges",
    "faces",
    "vertices",
    "volume_of",
    "area_of",
    "rasterize",
    "triangulate",
    "triangulation_of",
    "centroid_of",
    "aabb_of",
    "any_point",
    "edges_of",
    "faces_of",
    "vertices_of",
    "signed_distance",
    "boundary_of",

    #### BINARY ####
    "intersection",  # representation problem
    "intersects",
    "closest_points",
    "distance",
    "distance_sqr",
    "intersection_parameter",
    "intersection_parameters",
    "contains",  # potentially impl difficulty
    "project"
]

def get_dim_from_template(templ_args: str):
    templ_args = templ_args.strip()
    templ_args = templ_args[1:-1] #deleting enclosing "<" & ">"
    arg_list = templ_args.split(",")

    if(len(arg_list) >= 3 and not arg_list[2].strip().startswith('TraitsT')): # could be 2in3 case
        dim1 = arg_list[0].strip()
        dim2 = arg_list[2].strip()

        if dim1 == "ObjectD":
            dim1 = "O"

        if dim2 == "DomainD":
            dim2 = "D"

        if dim1 != dim2:
            return dim1 + "in" + dim2

    if arg_list[0] == "D" or arg_list[0].startswith("ObjectD"):
        return ""
    if arg_list[0] == "3":
        return "3"
    if arg_list[0] == "2":
        return "2"
    if arg_list[0] == "1":
        return "1"
    if arg_list[0] == "4":
        return "4"
    if arg_list[0] == ("BaseT"):
        return "3"

    return ""

    
def get_new_func_name(func_decl: str, params): #params: list of argument name strings
    s = func_decl
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
    function_name = return_type_and_function_name[-1] # first from the end

    if(not function_name in functions):
        return func_decl

    start_func_name = func_decl.find(function_name)
    length = len(function_name)

    first_part = func_decl[:start_func_name]
    third_part = func_decl[start_func_name+length:] #containing erverything from params on (Obj,....) -> ...

    # get argument dimensions and typenames for the renaming
    s = s[end_idx:] # containing arguments and evtl "-> return_type"
    params_with_dims = ""

    for arg in params:
        # get dim
        try:
            start_temp = arg.index("<")
            end_temp = arg.index(">")
            dim = get_dim_from_template(arg[start_temp: end_temp+1])
            # get type name isolated
            name = arg[:start_temp] 
            params_with_dims += "_" + name + dim
        except ValueError as ve:
            start_temp = arg.index(" ")
            name = arg[:start_temp]
            params_with_dims += "_" + name

    return first_part + function_name + params_with_dims + third_part


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

######## MAIN #######

# Rename all function names according to following schema:
# For unary functions: func_of_type'Dim'(...)
# For binary functions: func_type1'Dim'_type2'Dim'(...)

if not os.path.exists(out_file):
    os.makedirs(out_file)

for func_file in function_files:
    in_file = src_path + func_file
    text = open(in_file, "r").read()
    lines = text.split('\n')

    lines_updated = []

    line_index = 0

    while line_index < len(lines):
        line_temp = lines[line_index] + '\n'

        if line_temp.startswith("[[nodiscard]] constexpr"): # found a function
            start_args = line_temp.index('(')

            # args along multiple lines
            end_args = index_of_closing(line_temp, start_args)
            count = 0
            while(end_args == -1):
                line_temp += lines[line_index + count + 1] +'\n'
                end_args = index_of_closing(line_temp, start_args)
                count += 1
            
            line_index += count

            # arguments in string
            args = line_temp[start_args+1:end_args]
            args_list = []
            found_arg = True

            # separate arguments and store in 'args_list'
            while "const&" in args:
                try:
                    start = args.find("const&")
                    divisor = args[start:].index(',')
                    args_list.append(args[:divisor+start])
                    args = args[divisor+start+1:].strip()
                except ValueError as ve:
                    args_list.append(args)
                    break

            new_line = get_new_func_name(line_temp, args_list)
            line_temp = new_line

        lines_updated.append(line_temp)
        line_index += 1

    # Write them back to the file
    with open(out_file + func_file, 'w') as f:
        f.writelines(lines_updated)
