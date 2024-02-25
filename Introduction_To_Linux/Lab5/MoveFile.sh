#!/bin/bash

read -p "please enter a string: " NAME

if [ -e $NAME ]
	then if [ -d ${NAME}dir ]
		then mv $NAME ${NAME}dir
	else
		mkdir ${NAME}dir
		mv $NAME ${NAME}dir
	fi
else
	touch $NAME
	if [ -d ${NAME}dir ]
		then mv $NAME ${NAME}dir
	else
		mkdir ${NAME}dir
		mv $NAME ${NAME}dir
	fi
fi
