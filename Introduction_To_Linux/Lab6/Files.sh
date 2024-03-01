#!/bin/bash
# lines with # shows alternative solution: in case we want to change real files names
files_array=($(ls -1 *k*))
array_len=${#files_array[@]}

for ((i=0;i<$array_len;i++))
do
#  mv ${files_array[i]} ${files_array[i]}$(($i+1))
  echo ${files_array[i]}$(($i+1)) >> tmp_file
done

#ls -1 *k* | sort -t"k" -k2 > FileList
cat tmp_file | sort -t"k" -k2 > FileList
rm tmp_file
