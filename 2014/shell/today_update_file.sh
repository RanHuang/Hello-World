#########################################################################
# File Name: today_update_file.sh
# Author: Nick
# mail: xjhznick@gmail.com
# Created Time: Sun 19 Jul 2015 08:48:43 AM CST
# Description: 
#	Find files updated/created today
#	Usage: *.sh <dir>
#
#	data "+%Y-%m-%d"    in 'ls -l'  --time-style=long-iso 
#	var=$(<cmd>) 执行命令，使用格式$()
#########################################################################
#!/bin/bash
function recurse()
{
	cd $1

	for file in *; do
		if [[ -d $file ]]
		then
			recurse $file
		fi

		if [ -f $file ]; then
			longtimefile=$(ls -l --time-style=long-iso $file)
			check=$(echo $longtimefile | grep $today)
#			echo $longtimefile
#			echo $check

			if [ -n "$check" ]; then
				echo "$PWD/$file"
				echo $longtimefile
			fi
		fi
	done

	if [ "$1" != "." ]; then
		cd ..   #line 13: cd $1
	fi
}

function main()
{
	today=$(date "+%Y-%m-%d")

	checkdir=$1

	if [[ -z "$checkdir" ]]
	then
		checkdir="."
	fi

#	echo $checkdir
	recurse $checkdir
}

main $1

exit
