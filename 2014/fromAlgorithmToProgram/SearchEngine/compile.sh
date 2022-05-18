#########################################################################
# File Name: compile.sh
# Author: Nick
# mail: xjhznick@gmail.com
# Created Time: Thu 16 Jul 2015 07:33:52 PM CST
# Description: 
#########################################################################
#!/bin/bash

gcc -g -c searchengine.c -I../utility
gcc -g -o searchengine searchengine.o ../utility/search.o ../utility/compare.o ../utility/strstream.o 
