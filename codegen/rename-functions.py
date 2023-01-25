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
    "intersects"
    "closest_points",
    "distance",
    "distance_sqr",
    "intersection_parameter",
    "intersection_parameters",
    "contains",  # potentially impl difficulty
    "project"
]

# parse a file and change function names
def get_new_func_name(func_decl: str, unary: bool):
    dim = "-1" 

    ##### look for dimension #####
    t = func_decl
    t_index = t.index("(")
    t = t[t_index:]
    try:
        dim_index = t.index("<")
        if t[dim_index + 1] == "D" or t[dim_index + 1:].startswith("ObjectD"):
            dim = ""
        if t[dim_index + 1] == "3":
            dim = "3"
        if t[dim_index + 1] == "2":
            dim = "2"
        if t[dim_index + 1] == "1":
            dim = "1"
        if t[dim_index + 1] == "4":
            dim = "4"
        if t[dim_index + 1:].startswith("BaseT"):
            dim = "3"

    except ValueError as ve:
        dim = ""
    ##### #####

    #start_param = func_decl.index("(")
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
    function_name = return_type_and_function_name[-1]

    if(not function_name in functions):
        return func_decl

    s = s[end_idx:]

    start_func_name = func_decl.find(function_name)
    length = len(function_name)

    first_part = func_decl[:start_func_name]
    third_part = func_decl[start_func_name+length: len(func_decl)]

    # get argument names
    function_arguments = s[end_idx:]
    end_first_arg = 0
    first_arg = " "

    end_func_decl = -1
    try:
        end_func_decl = s.index("->")
    except ValueError as ve:
        end_func_decl = len(s)

    s = s[:end_func_decl]
        
    try:
        end_first_arg = s.index("<")
        first_arg = s[1:end_first_arg]
    except ValueError as ve:
        return (first_part + function_name + "TODO_MANUALLY" + third_part)

    s = s[s.index(">"):] # cut off first argument

    start_second_arg = 0
    end_second_arg = 0
    second_arg = ""

    if(not unary):
        try:
            start_second_arg = s.index(", ")
            end_second_arg = s.index("<")
            second_arg = s[start_second_arg+2:end_second_arg]
        except ValueError as ve:
            return (first_part + function_name + "TODO_MANUALLY" + third_part)

        return (first_part + function_name + "_" + first_arg + dim + "_" + second_arg + dim + third_part)

    else:
        return (first_part + function_name + "_" + first_arg + dim + third_part)



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
        #TODO: Check binary or unary function and call correct function
        line_temp = lines[line_index] + '\n'

        if line_temp.startswith("[[nodiscard]] constexpr"):
            ########## separate function
            start_args = line_temp.index('(')

            # DEBUG
            #print(line_temp + "line: " +  str(line_index))

            # args along multiple lines
            try:
                end_args = line_temp.index(')')
            except ValueError as ve:
                line_temp = lines[line_index] + lines[line_index+1] + '\n'
                try:
                    end_args = line_temp.index(')')
                except ValueError as ve:
                    line_temp = lines[line_index] + lines[line_index+1] + lines[line_index+2] + 'n'
                    end_args = line_temp.index(')')

            args = line_temp[start_args:end_args]

            found_arg = True


            while found_arg:
                #print(args)
                try:
                    start = args.index('<')
                    end = args.index('>')
                    args = args[start-1] + args[end+1:]
                except ValueError as ve:
                    found_arg = False

            args = args.split(",")

            #print(args)

            unary = (len(args) == 1)
            # TEST
            #if unary:
            #    print("unary function: " + str(args))
            #else:
                #print("binary function")
            #########################
            new_line = get_new_func_name(line_temp, unary)
            line_temp = new_line

        lines_updated.append(line_temp)
        line_index += 1

    # Parse the file into lines
    # with open(in_file, 'r') as f:
    #     for line in f:
    #         if line.startswith("[[nodiscard]] constexpr"):
    #             new_line = get_new_func_name(line)
    #             line = new_line
    #         
    #         lines_updated.append(line)

    # Write them back to the file
    with open(out_file + func_file, 'w') as f:
        f.writelines(lines_updated)

        # Or: f.write(''.join(lines))

    # line_index = 0
    # 
    # while line_index < len(lines):
    #     line_index += 1
    # 
    # print(line_index)
    #lines = text.split(/n)msg = "Test"
    #print(msg)
