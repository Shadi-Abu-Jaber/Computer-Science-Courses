#!/bin/bash

###############################################################################
# Q1
passed_parameters=$#
if [[ "$passed_parameters" != "2" ]]; then
	echo "Usage: beatles-info.sh <Beatles-dir> <out-dir>"
	exit 1
fi

beatles_dir=$1
out_dir=$2
###############################################################################
# Q2
if [[ ! -d "$beatles_dir"  ]]; then
	echo "Error: $beatles_dir does not exist or is not a directory"
	exit 1
fi
###############################################################################
# Q3
if [[ -d "$out_dir"  ]]; then
	echo -n "Warning: beat already exists, overwrite? (y/n): "; read REPLY
	if [[ "$REPLY" == "n"  ]]; then
		echo "Aborting"
		exit 1
	elif [[ "$REPLY" == "y"  ]]; then
		rm -rf "$out_dir"
	fi
fi
mkdir "$out_dir"
###############################################################################
# Q4
num_songs=$(ls -1 "$beatles_dir" | wc -l)
echo "There are $num_songs songs in the Beatles catalog"
###############################################################################
# Q5
comes_appearances=$(tail -n +3 "${beatles_dir}/herecomesthesun.txt" |tr " " "\n" | grep "comes" | wc -l)
echo "The word comes appears $comes_appearances times in the song Here comes the sun"
###############################################################################
# Q6
total_words=0
for file in ${beatles_dir}/*.txt ; do
	num_words=$(tail -n +3 "$file" | tr " " "\n" | wc -w)
	total_words=$(( total_words + num_words))
done
avg=$((total_words / num_songs))
echo "On average, there are $avg words in each song"
###############################################################################
# Q7
for file in ${beatles_dir}/*.txt ; do
	song_name=$(head -n 1 "$file")
	most_frequent_word_line=$(tail -n +3 "$file" | tr ' ' '\n' | sort | uniq -c | sort -br | head -n 1 )
	echo -e "$song_name\t$most_frequent_word_line" >> "${out_dir}/beatles.most-frequent-word.txt"
done
###############################################################################
# Q8
echo "Word occurrence in the Beatles songs is:" >> "${out_dir}/beatles.word-occurrences.txt"
for file in ${beatles_dir}/*.txt ; do

	tail -n +3 "$file" | tr -d '.' | tr -d '(' | tr -d ')' | tr -d '!' | tr -d ',' | tr ' ' '\n'

done |sort -f | uniq -ci | sort -rn  >> "${out_dir}/beatles.word-occurrences.txt"
###############################################################################
# Q9
echo "The number of song names starting at each letter in the ABC: " >> "${out_dir}/beatles.song-names-abc.txt"
songs_names_ABC=$(ls -1 "$beatles_dir" | cut -c 1 | sort | uniq -c | sed 's/[a-z]/\U&/g')
echo "$songs_names_ABC" >> "${out_dir}/beatles.song-names-abc.txt"
###############################################################################
# beatles.wc.txt file
for file in ${beatles_dir}/*.txt ; do
 	song_name=$(head -n 1 "$file")
	num_lines=$(tail -n +3 "$file" | wc -l)
	num_words=$(tail -n +3 "$file" | wc -w)
	num_chars=$(tail -n +3 "$file" | wc -c)
	echo -e "$song_name\t $num_lines $num_words $num_chars" >> "${out_dir}/beatles.wc.txt"
done
###############################################################################
# Q10
while true;do
	echo -n "enter a word to look for (X to stop): "; read REPLY
	if [[ "$REPLY" == "X"  ]]; then
		exit
	fi
	num_appearnces=0
	for file in ${beatles_dir}/*.txt; do
		appeared=$(tail -n +3 "$file" | grep -i "$REPLY")
		if [[ "$appeared" != ""  ]]; then
			num_appearnces=$((num_appearnces + 1))
		fi
	done
	echo "The word $REPLY appears in $num_appearnces songs"
done
###############################################################################
