#########################################################################
# File Name: show_users.sh
# Author: Nick
# mail: xjhznick@gmail.com
# Created Time: Sun 19 Jul 2015 12:22:10 AM CST
# Description: 
#	echo -n 打印 & 不换行
#########################################################################
#!/bin/bash

#save current directory
curpwd=$PWD

#change to /home directory
cd /home

echo -n "Users on this system are: "

#Loop
for user in *; do
	echo -n "$user"
done

echo

#return to previous directory
cd $curpwd

exit
