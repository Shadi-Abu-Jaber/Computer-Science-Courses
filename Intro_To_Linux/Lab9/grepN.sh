#!/bin/bash
file=$1
echo -e "printing file lines...\n"
line_number=1
while read line; do
	echo "$line_number $line"
	line_number=$((line_number + 1))
done < "$file"
