#!/bin/bash
################################################################################
# ex2.b
calcStdNames(){
	students_file=$1
	students_names=$(cut -d" " -f 1 $students_file | sort -k1 | uniq -c)
	echo "$students_names"
}
################################################################################
# ex2.c
CalcGPA(){
	students_file=$1
	YEAR=$2
	if [[ $# -ne 2  ]]; then
	echo -e "\nUsage: $0 <StudentFile> <YEAR> \n"
	fi
	if  ((YEAR < 1900 || YEAR > 2010 )); then
	echo "invalid year!"
	fi
	students=$(grep "$YEAR" $students_file | sort -t" " -k 4)
	echo "$students"
}
################################################################################
# ex3.d
students_file=$1
YEAR=$2
calcStdNames $students_file > Names.txt
CalcGPA $students_file $YEAR >  GPA.txt
