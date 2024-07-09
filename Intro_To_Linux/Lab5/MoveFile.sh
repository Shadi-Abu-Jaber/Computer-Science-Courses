#!/bin/bash

read -p "please enter a string: " NAME

if [ -e $NAME ]
then
    echo -e "file exists!\n"
    if [ -d ${NAME}dir ]
    then
        echo -e "dir exists!\n"
	mv $NAME ${NAME}dir
    else
    	echo -e "dir does not exist,I will make one\n"
	mkdir ${NAME}dir
	mv $NAME ${NAME}dir
    fi
else
    echo -e "file does not exist, I will make one\n"
    touch $NAME
    if [ -d ${NAME}dir ]
    then
        echo -e "dir exists!\n"
	mv $NAME ${NAME}dir
    else
        echo -e "dir does not exists, I will make one\n"
	mkdir ${NAME}dir
	mv $NAME ${NAME}dir
    fi
fi
