#########################################################################
# File Name: get_proc_stat.sh
# Author: Nick
# mail: xjhznick@gmail.com
# Created Time: 2015年07月17日 星期五 16时16分08秒
#########################################################################
#!/bin/bash
rm -f procstat.txt
for((i=0;i<30;i+=1)); do
	cat /proc/stat | grep intr >> procstat.txt
	sleep 1
done
exit
