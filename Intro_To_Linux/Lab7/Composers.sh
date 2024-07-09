#!/bin/bash

#question 3.a
#first_names () {
#cut -d" " -f1,3 $1 > FirstYear
#}
#first_names $@

cutter () {
input=$1
if [ "$input" == "FN" ]
then
    cut -d" " -f1 ComposersFile > "$input"
elif [ "$input" == "SN" ]
then
    cut -d" " -f2 ComposersFile > "$input"
elif [ "$input" == "Year" ]
then
    cut -d" " -f3 ComposersFile > "$input"
elif [ "$input" == "Country" ]
then
    cut -d" " -f4 ComposersFile > "$input"
else
    echo "invalid option"
fi
}
cutter $@
