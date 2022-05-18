#!/bin/sh
echo "Exit the program,Yes or No?"
while true
do
	read ans
	if [ "$ans"x = "Yes"x ]
	then
		echo "$ans"
		break
	else
		echo "Continue"
		continue
	fi
done
