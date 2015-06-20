/*************************************************************************
	> File Name: time.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月12日 星期四 18时47分21秒
  > Description:有关获取时间的函数
 ************************************************************************/

#include<stdio.h>
#include<time.h>

int main(int argc, char *argv[])
{
	time_t mytime;
	struct tm *my_localtime;
	char *str_time;

	mytime = time(NULL);
	my_localtime = localtime(&mytime);
	str_time = asctime(my_localtime);
	puts("Local time is(sactime) : ");
	puts(str_time);

	sleep(2);

	mytime = time(NULL);
	str_time = ctime(&mytime);
	printf("Local time is(ctime) : %s\n", str_time);

	return 0;
}
