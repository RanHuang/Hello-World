#########################################################################
# File Name: basic_env.sh
# Author: Nick
# mail: xjhznick@gmail.com
# Created Time: Sat 18 Jul 2015 11:56:21 PM CST
# Description: 
#########################################################################
#!/bin/bash
echo "Host:  $HOSTNAME	OS type: $OSTYPE."
echo "You:   $USER		home: $HOME."
echo "Shell: $SHELL		version: $BASH_VERSION."
echo "PATH:  $PATH."
echo "PWD:   $PWD."
echo "PPID:  $PPID."
#sleep 2
echo "Script running time: $SECONDS second(s)."
exit
