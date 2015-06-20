/*************************************************************************
	> File Name: abort_sample.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月24日 星期二 08时09分12秒
  > Description:abort()异常终止函数
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	printf("Before abort()\n");
	abort();
	printf("After abort()\n");
	return 0;
}
