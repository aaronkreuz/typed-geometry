
in_file = "../src/typed-geometry/functions/objects/distance.hh"
out_file = "test.hh"

# text contains content of specified file
text = open(in_file, "r").read()
# text = f.read()

# parse a file and change function names
def get_new_func_name(func_decl: str):
    dim = "-1" 

    ##### look for dimension #####
    t = func_decl
    t_index = t.index("(")
    t = t[t_index:]
    try:
        dim_index = t.index("<")
        if t[dim_index + 1] == "D":
            dim = ""
        if t[dim_index + 1] == "3":
            dim = "3"
        if t[dim_index + 1] == "2":
            dim = "2"

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

    try:
        start_second_arg = s.index(", ")
        end_second_arg = s.index("<")
        second_arg = s[start_second_arg+2:end_second_arg]
    except ValueError as ve:
        return (first_part + function_name + "TODO_MANUALLY" + third_part)

    return (first_part + function_name + "_" + first_arg + dim + "_" + second_arg + dim + third_part)


# stores lines in array(?) -> access via 
lines = text.split('\n')

lines_updated = []

line_index = 0

while line_index < len(lines):
    line_temp = lines[line_index] + '\n'
    if line_temp.startswith("[[nodiscard]] constexpr"):

        new_line = get_new_func_name(line_temp)
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
with open(out_file, 'w') as f:
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
