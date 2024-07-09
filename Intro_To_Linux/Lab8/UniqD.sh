#!/bin/bash

file="$1"
sort $file > sorted_file.txt
prev_line=""
count=0

while read -r line
do
	if [ "$line" == "$prev_line" ]
	then
		count=$(( count + 1 ))
	else
        	if (( count > 1 ))
        	then
		echo "$prev_line"
        	fi
        	count=1
        fi
	prev_line="$line"

done < sorted_file.txt

# if there is duplicates at the end of the file
if (( count > 1 ))
then
    echo "$prev_line"
fi

rm sorted_file.txt
