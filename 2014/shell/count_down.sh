#########################################################################
# File Name: count_down.sh
# Author: Nick
# mail: xjhznick@gmail.com
# Created Time: Fri 11 Mar 2016 09:00:30 PM CST
# Description: 
#########################################################################
#!/bin/bash

echo -n Count: 

tput sc #store the position

if [ 0 = $# ]; then
	count=8
else
	count=$1
fi

echo -n $count
while true; do
	if [ $count -gt 0 ]; then
		let count--
		sleep 1
		tput rc #recover the position
		tput ed
		echo -n $count
	else
		echo
		exit 0
	fi
done

