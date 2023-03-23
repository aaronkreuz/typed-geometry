import os
import json
import numpy as np
import processing as ofp

class geo_type:
    def __init__(self, name: str, file: str) -> None:
        self.name = name
        self.fileName = file
        self.objectDimDependence = False
        self.objectDim = ""
        self.domainDim = ""
        self.templateForm = "<>"
        self.BoundaryTag = False

    def find_templateForm(self) -> None:
        if (self.fileName +'.hh') in os.listdir(ofp.type_path):
            in_file = ofp.type_path + self.fileName +'.hh'
        else:
            in_file = ofp.type_path + "objects/" + self.fileName + '.hh'

        text = open(in_file, "r").read()

        lines = text.split('\n')
        line_index = 0

        while line_index < len(lines):
            line_temp = lines[line_index]

            if line_temp.startswith('template'):
                line_next = lines[line_index+1]

                if self.name in line_next:
                    start_ind = line_next.index(self.name)
                    if not (start_ind + len(self.name) > (len(line_next) - 1)):
                        if not (line_next[start_ind + len(self.name)] != " " or line_next[start_ind + len(self.name)] != ";"):
                            # wrong type declaration -> continue searching
                            line_index += 1
                            continue    
                    
                # line containing template info about the type
                start_template = line_temp.index('<')
                end_template = ofp.index_of_closing(line_temp, start_template)

                self.templateForm = line_temp[start_template:end_template+1]

            line_index += 1
    
        # default case -> might not be matching
        self.templateForm = "<int D, class ScalarT>"

        if "ObjectD" in self.templateForm:
            self.objectDimDependence = True

    def set_domainDim(self, dim: str) -> None:
        self.domainDim = dim
    
    def set_objectDim(self, dim: str) -> None:
        self.objectDim = dim

    def is_obj_dim_dependent(self) -> bool:
        # defensive code
        if self.templateForm == "<>":
            self.find_templateForm(ofp.type_path)

        return self.objectDimDependence
    
    def get_name(self) -> str:
        return self.name
    
    def get_type_name(self) -> str:
        return self.fileName

        


    