#/bin/sh
for filename in *
do
#	echo $filename
	if test -f $filename
	then 
		ls -l $filename
	fi
done
