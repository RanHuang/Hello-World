#!/bin/sh
myfind()
{
	if [ $# -lt 1 ]
	then 
		echo "Usage: myfind filename"
		return 1
	fi
	find ~/ -name $1 -print
}
