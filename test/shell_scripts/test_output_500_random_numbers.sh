#!/usr/bin/env bash

LINES_IN_FILES=0
TOTAL_LINES=0
MAX_LINES=0
MIN_LINES=$(wc -l < ../test_output_files/test_500/test_500_numbers1.txt)
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
SUPER_RED="\033[91m"
SUPER_GREEN="\033[92m"
SUPER_YELLOW="\033[93m"
SUPER_BLUE="\033[94m"
SUPER_MAGENTA="\033[95m"
SUPER_CYAN="\033[96m"

for i in $(seq 1 100); do
	LINES_IN_FILES=$(wc -l < "../test_output_files/test_500/test_500_numbers$i.txt");
	if [ "$LINES_IN_FILES" -gt "$MAX_LINES" ]; then MAX_LINES=$LINES_IN_FILES; fi;
	if [ "$LINES_IN_FILES" -lt "$MIN_LINES" ]; then MIN_LINES=$LINES_IN_FILES; fi;
	if [ "$LINES_IN_FILES" -gt "5500" ];
		then echo "The file test_500_numbers$i.txt has: $SUPER_RED$LINES_IN_FILES$WHITE lines";
	else
		echo "The file test_500_numbers$i.txt has: $SUPER_GREEN$LINES_IN_FILES$WHITE lines";
	fi;
	TOTAL_LINES=$(($TOTAL_LINES + $LINES_IN_FILES));
done
echo "$MAGENTA Total lines in all files: $TOTAL_LINES$WHITE"
echo "$BLUE The average lines per file is: $(($TOTAL_LINES / 100))$WHITE"
if [ "$MAX_LINES" -gt "5500" ];
	then echo "The file with the most lines has: $SUPER_RED$MAX_LINES$WHITE lines";
else
	echo "The file with the most lines has: $SUPER_GREEN$MAX_LINES$WHITE lines";
fi;
if [ "$MIN_LINES" -gt "5500" ];
	then echo "The file with the least has: $SUPER_RED$MIN_LINES$WHITE lines";
else
	echo "The file with the least lines has: $SUPER_GREEN$MIN_LINES$WHITE lines";
fi;