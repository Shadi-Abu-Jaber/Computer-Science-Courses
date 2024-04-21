#!/bin/bash
################################################################################
if [[ "$#" -ne 2 ]]; then
    echo "\nUsage: $0 <python_file> <text_file>\n"
    exit 1
fi

python_file=$1
text_file=$2

result_file=$(echo "$python_file" | cut -d"." -f1)Result.txt

python "$python_file" > "$result_file"

diff_lines=$(diff "$text_file" "$result_file" | wc -l)

if [[ "$diff_lines" -eq 0 ]]; then
	echo "Your python code is correct"
else
	echo "Your python code is wrong"
fi
################################################################################
