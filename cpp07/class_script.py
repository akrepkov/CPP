#!/usr/bin/env python3
#python ./class_script.py

class_name = input("Class name: ")

#The triple quotes (""") in Python denote a multi-line string literal. 
class_template = f"""

#ifndef {class_name}_HPP
#define {class_name}_HPP

class {class_name}{{
	private:

	public:
		{class_name}();
		~{class_name}();
		{class_name}& operator=(const {class_name}& copy);
		{class_name}(const {class_name}& copy);

}};

#endif
"""

class_cpp = f"""

#include "{class_name}.hpp"

{class_name}::{class_name}() {{
}}

{class_name}::~{class_name}() {{
}}

{class_name}& {class_name}::operator=(const {class_name}& copy) {{
	if (this != &copy) {{
	}}
    return *this;
}}

{class_name}::{class_name}(const {class_name}& copy) {{
	*this = copy;
}}
"""

with open(f"{class_name}.hpp", "w") as file:
    file.write(class_template)

with open(f"{class_name}.cpp", "w") as file:
    file.write(class_cpp)

