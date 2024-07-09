#!/bin/bash

fact(){
	if (($1 == 0)); then
		echo 1
	else
		echo $(($1 * $(fact $(( $1 - 1 ))) ))
	fi
}
result=$(fact $1)
echo "Factorial of $1 is: $result"
