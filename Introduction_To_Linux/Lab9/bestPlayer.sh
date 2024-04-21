#!/bin/bash

# you did not explain how player funtion should get the file
# in the assignment you said that player func takes one parameter

search(){
	string=$1
	file_name=$2
	grep -rn "$string" "$file_name"
}
#search $1 $2
################################################################################
player(){
	player_name=$1
	file_name="football.txt"
	totalt_goals=0
	goals=$(grep -r "$player_name" "$file_name" | cut -d" " -f 3)
	for goal in $goals; do
		totalt_goals=$((totalt_goals + goal))
	done
	#echo "Total numbers of goals: $totalt_goals"
	echo "$player_name $totalt_goals"
}
#player $@
################################################################################
best_player(){
	best=$(player $1)
	for player in $@; do
		curr_player=$(player "$player" | cut -d" " -f 2)
		curr_best=$(echo "$best" | cut -d" " -f 2)
		if ((curr_player > curr_best)); then
			best="$player $curr_player"
		fi
	done

	goaler=$(echo "$best" | cut -d" " -f 2)
	for player in $@; do
		curr_player=$(player "$player" | cut -d" " -f 2)
		if ((curr_player == goaler)); then
			echo "$player $curr_player"
		fi
	done
}
best_player $@
################################################################################
