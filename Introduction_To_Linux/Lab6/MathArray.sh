#!/bin/bash
read -p "please enter a positive number: " NUM
arr=()
sum=0

for ((i=0;i<NUM;i++))
do
  read -p "please enter a number to add it to array: " arr_num
  arr[i]=$arr_num
  sum=$(($sum + ${arr[i]}))
done

max_num=${arr[0]}

for ((i=0;i<NUM;i++))
do
  if((${arr[i]} > $max_num))
  then
      max_num=${arr[i]}
  fi
done

echo "array: ${arr[@]}"
echo "sum of array: $sum"
echo "max number in array: $max_num"
