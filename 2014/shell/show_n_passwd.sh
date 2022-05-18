#!/bin/bash
#
#	show the firt n lines of the /etc/passwd

#	Usage: *.sh n
CAT()
{
	cat /etc/passwd | head -$line
}
echo -n "Input the number of lines: "
read line
limit=6
#space ' ' between if and '[' required.
if [ $limit -gt $line ] 
then
	while [ -n $line ]
	do 
		CAT
		break 2
	done
#
	echo -n "Continue?(answer yes/no):"
	read answer
	if [ $answer='yes' ]
	then
		let line=line+1 #no space before or after '+'
		CAT
	fi
fi
exit 0
