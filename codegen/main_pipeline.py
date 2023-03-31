import os
import fixpoint
import function_parser_experimental as parser
import object_function_generator as generator
import processing as ofp

### 1st step: parsing ###
if not os.path.exists(ofp.renamed_files_path):
    os.makedirs(ofp.renamed_files_path)

if not os.path.exists(ofp.function_list_path):
    os.makedirs(ofp.function_list_path)

parsed_files = []

for file in ofp.function_files:
    in_file = ofp.src_function_path + file
    text = open(in_file, "r").read()
    file_json = parser.parse_functions(text, file[:-3])
    parsed_files.append((file, file_json))

parsed_files = dict(parsed_files)

### 2nd step: fixpoint-iterations ###
# perform on parsed files
it_count = 0
max_iterations = 1 # max number of iterations until iteration stops
change_flag = True # indicate if any changes appeared in current fixpoint step

if not os.path.exists(ofp.function_list_path):
    os.makedirs(ofp.function_list_path)

while change_flag and (it_count < max_iterations):
    # DEBUG
    # print ("iteration: " + str(it_count + 1))
    change_flag = False
    change_flag = True if fixpoint.fixpoint_iteration_step_unary(parsed_files) else change_flag
    change_flag = True if fixpoint.fixpoint_iteration_step_binary_symmetric(parsed_files) else change_flag
    change_flag = True if fixpoint.fixpoint_iteration_step_binary_asymmetric(parsed_files) else change_flag
    it_count += 1

# 3rd object function generation


