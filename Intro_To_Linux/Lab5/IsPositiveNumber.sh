#!/bin/bash
read -p "please enter a number: " num

if (($num<0))
then
    echo -e "$num is a negative number\n"
elif (($num>0))
then
    echo -e "$num is a positive number\n"
else
    echo -e "it's a ZERO!\n"
fi
