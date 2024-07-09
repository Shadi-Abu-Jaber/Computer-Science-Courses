#!/bin/bash
############################################
mult () {
local result=1
for num in $@
do
  let result*=$num
done
echo "$result"
}
#result=`mult $@`
#echo "Result => $result"
############################################
isEven () {
num=$1
if(( $num % 2 == 0 ))
then
    echo "1"
else
    echo "0"
fi
}
#isEven $@
############################################
numOfEvens () {
even_nums=0
for num in $@
do
  is_even=`isEven $num`
  if [ "$is_even" == "1" ]
  then
      let  even_nums+=1
  fi
done
echo "even numbers = $even_nums"
}
#num_of_evens=`numOfEvens $@`
#echo "num of even numbers => $num_of_evens"
############################################
fibo () {
num=$1
if (( num <= 0 ))
then
    echo "0"
fi
n1=0
n2=1
echo -n "$n1"
for ((i=1;i<num;i++))
do
  echo -n " $n2"
  temp=$n2
  n2=$((n1 + n2))
  n1=$temp

done
}
#echo `fibo 4`
#echo `fibo 10`
############################################
minMax () {
min=$1
max=$1
for num in $@
do
  if ((num >= max))
  then
      max=$num
  fi

  if ((num <= min))
  then
      min=$num
  fi
done
echo "min = $min, max = $max"
}
#minMax $@
#echo "min = $min, max = $max"
############################################
main () {
echo "which function would you choose:"
echo "mult => enter 1"
echo "numOfEvens => enter 2"
echo "minMax => enter 3"
read -p "function: " fun

if [ "$fun" == "1" ]
then
    mult $@
elif [ "$fun" == "2" ]
then
    numOfEvens $@
elif [ "$fun" == "3"  ]
then
    minMax $@
else
    echo "invalid option" > Errors.er
fi
}
############################################
main $@
