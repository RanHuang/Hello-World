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
	my_localtime = localtime(&mytime);//将long型s时间转换为结构体时间
	str_time = asctime(my_localtime); //转换为字符串时间
	puts("Local time is(sactime) : ");
	puts(str_time);

	sleep(2);//延迟2s,相当于delay(2000)

	mytime = time(NULL);
	str_time = ctime(&mytime);
	printf("Local time is(ctime) : %s\n", str_time);

	return 0;
}
