#!/bin/bash
read -p "please enter a number: " num

if [ "$num" -ge 10 -a  "$num" -le 100 ]
	then echo -e "$num is between 10 and 100\n"

else
	 echo -e "$num is not between 10 and 100\n"
fi
