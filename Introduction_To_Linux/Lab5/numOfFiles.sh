#!/bin/bash
read -p "please enter a number: " num

files_and_dirs=$(ls -1 | wc -l)

if (($files_and_dirs == $num))
	then echo -e "number of files and dirs in current dir is equal to the given number => ${num}\n"
else
	echo -e "number of files and dirs in current dir is not equal to the given number => ${num}\n"
fi
