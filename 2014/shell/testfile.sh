#!/bin/sh
if test -f Readme
then
	echo "ordinary file"
else
	echo "Readme"
fi
if [ -x ~/Public/linuxC/testfile.sh ]
then
	echo "execeded file"
else
	echo "testfile.sh"
fi
