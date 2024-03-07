#!/bin/bash
curr_dir=`pwd`
############################################
cut_4_chars () {
first_four=`echo "$1" | cut -c 1-4`
echo "$first_four"
}
############################################
count_files () {
counter=0
for file in `ls $curr_dir`
do
  if [ -f "$file"  ]
  then
      first_four=`cut_4_chars "$file"`
      if [ "$first_four" == "$1"  ]
      then
          let counter+=1
      fi
  fi
done
echo "$counter"
}
############################################
transfer_files () {
for file in `ls $curr_dir`
do
  if [ -f "$file" ]
  then
      dir_name=`cut_4_chars "$file"`
      num_files=`count_files "$dir_name"`

      if [ -d "$dir_name" ]
      then
          mv "$file" "$dir_name"
      elif ((num_files >= 3))
      then
          mkdir "$dir_name"
          mv "$file" "$dir_name"
      fi
  fi
done
}
############################################
transfer_files
