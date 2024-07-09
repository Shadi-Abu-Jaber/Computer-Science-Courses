#!/bin/bash

num_places=$1
num_candidates=$(cat "Moogle.grades" | wc -l)

if ((num_candidates < num_places ))
then
	echo "Not enough interviewees"
fi

ids=$(sort -t" " -k 1 "Moogle.grades" | cut -d" " -f 1)
final=()

sum_score() {
	i=0
	for id in $ids; do
		score=0
		veto=false
		id_lines=$(cat *.grades | sort | grep "$id")
		while read -r line; do
			fields=($line)
			if [ "${fields[3]}" == "-NO-" ]; then
				veto=true
			else
				score=$((score + ${fields[3]}))
			fi
		done <<< "$id_lines"
		if [ "$veto" == "false" ]; then
			final[$i]="${fields[0]} ${fields[1]} ${fields[2]} $score"
			i=$((i + 1))
		fi
	done
}

sum_score

passed=$(
for ((i = 0; i < $num_candidates; i++)); do
    echo "${final[i]}"
done | sort -t" " -k4 -nr | cut -d" " -f1-3  | head -n $num_places)

num_passed=$(echo "$passed" | wc -l)

if ((num_passed >= num_places)); then
	echo "$passed"
else
	echo "Not enough interviewees"
fi
