#!/bin/bash
PERMITIONS=$1
total_num_files=0
for ((i=1;i<10;i++));do
	num_files=$(echo "$PATH"| cut -d":" -f $i |grep "$PERMITIONS" -r | wc -l)
	total_num_files=$((total_num_files + num_files))
done
echo "there is $total_num_files files which have $PERMITIONS permission in PATH Environmental Variable "
