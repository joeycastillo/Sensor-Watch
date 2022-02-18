# MIT License
#
# Copyright (c) 2022 David Keck
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import os
import re
import sys
import datetime
import argparse


MAKEFILE_INDICATOR = "# New watch faces go above this line.\n"
INCLUDE_INDICATOR = "// New includes go above this line.\n"


def replace_placeholders(contents, args):
    modified_contents = contents.replace("<#WATCH_FACE_NAME#>", args.watch_face_name.upper())
    modified_contents = modified_contents.replace("<#watch_face_name#>", args.watch_face_name)
    modified_contents = modified_contents.replace("<#year#>", datetime.datetime.now().strftime("%Y"))
    if args.author_name:
        modified_contents = modified_contents.replace("<#author_name#>", " ".join(args.author_name))

    return modified_contents


def write_modified_template(args, file_type, output_dir):
    with open(f"template.{file_type}", 'r') as file_template:
        file_contents = file_template.read()
    modified_template = replace_placeholders(file_contents, args)
    file_path = f"{output_dir}{args.watch_face_name}_face.{file_type}"
    if not os.path.exists(file_path):
        with open(file_path, 'w') as output_file:
            output_file.write(modified_template)
        print(f"Created {file_path}.")
    else:
        print(f"Generation failed: the watch face \"{args.watch_face_name}\" already exists at {file_path}. Unable to generate new files. Exiting...")
        sys.exit(0)


def update_include_file(file_path, indicator_line, line_to_insert):
    with open(file_path, 'r+') as include_file:
        include_contents = include_file.readlines()
        if line_to_insert not in include_contents:
            new_face_index = include_contents.index(indicator_line)
            include_contents.insert(new_face_index, line_to_insert)
            include_file.seek(0)
            include_file.writelines(include_contents)
            print(f"Updated {file_path}.")
        else:
            print(f"Generation failed: {file_path} already has an entry for {line_to_insert.strip()}. Unable to generate new files. Exiting...")
            sys.exit(0)


def main():
    parser = argparse.ArgumentParser(description="Create a new watch face.")
    parser.add_argument("watch_face_type", metavar="face_type", type=str, choices=["clock", "complication", "demo", "sensor", "settings"], help="The type of watch face to create ('clock', 'complication', 'demo', 'sensor', 'settings')")
    parser.add_argument("watch_face_name", metavar="face_name", type=str, help="The name of the watch face. Use underscores between words if you have more than one.")
    parser.add_argument("--author-name", metavar="author_name", type=str, nargs='*', help="The name of the author")

    args = parser.parse_args()

    name_valid = re.fullmatch(r'[a-zA-Z_][a-zA-Z0-9_]*', args.watch_face_name)
    if name_valid is None:
        print(f"Generation failed: {args.watch_face_name} is not a valid C variable name. Exiting...")
        sys.exit(0)

    if not args.author_name:
        print("Note: the \"--author-name\" argument was not supplied via command line. \"<#author_name#>\" will not be replaced in generated template.")

    line_to_insert = f"#include \"{args.watch_face_name}_face.h\"\n"
    update_include_file(f"..{os.sep}movement_faces.h", INCLUDE_INDICATOR, line_to_insert)

    line_to_insert = f"  ..{os.sep}watch_faces{os.sep}{args.watch_face_type}{os.sep}{args.watch_face_name}_face.c \\\n"
    update_include_file(f"..{os.sep}make{os.sep}Makefile", MAKEFILE_INDICATOR, line_to_insert)

    output_dir = f"..{os.sep}watch_faces{os.sep}{args.watch_face_type}{os.sep}"
    write_modified_template(args, "h", output_dir)
    write_modified_template(args, "c", output_dir)

    print(f"Successfully generated the {args.watch_face_name} {args.watch_face_type} and updated include files.")


if __name__ == "__main__":
    main()
