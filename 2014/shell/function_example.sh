#########################################################################
# File Name: function_example.sh
# Author: Nick
# mail: xjhznick@gmail.com
# Created Time: Sun 19 Jul 2015 12:31:59 AM CST
# Description: 
#	$#	参数个数
#	$?	上一个函数、程序返回值
#########################################################################
#!/bin/bash

function sum()
{
	if [ $# -ne 2 ]; then
		echo "Usage: sum <param1> <param2>"
		exit
	fi

	return $(($1 + $2))
}

#sum 10 5
sum $1 $2
ret=$?

echo $ret
