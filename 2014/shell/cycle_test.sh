#!/bin/sh
#创建、删除文件，退出循环
cd ~/Public/execute
while true
do
	echo "Select the operation:\n1    :Create a file;\n2    :Remove a file;\nother:Exit"
	read select
#	echo $select
	if [ "$select" = 1 ]
	then
		echo "Enter the filename to Create:"
		read filename
		if [ -e $filename ]
		then
			echo "The file is already existed."
			continue
		else
			touch $filename
		fi
	elif [ "$select" = 2 ]
	then
		echo "Enter the filename to remove:"
		read filename
		if [ -e $filename -a -f $filename ]
		then
			rm $filename
			echo "$filename is removed."
		else
			echo "The file is not existed, or not a regular file."
			continue
		fi
	else
		echo "Progress will be exited, Yes or No?"
		read answer
		if [ "$answer" = "Yes" ]
		then
			break
		else
			continue
		fi
	fi
done
exit
