/*************************************************************************
	> File Name: mystrcat.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月21日 星期六 16时18分02秒
  > Description: 实现自己的strcat函数功能
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STR_SIZE 50
char* mystrcat(char *dest, char *src);
int main(int argc, char *argv[])
{
	char *dest;
	char src[] = "my name is Linux C.";
	dest = (char*)malloc(STR_SIZE);
	strcpy(dest, "Hello, ");

	mystrcat(dest, src);
	printf("New str : %s\n", dest);

	return 0;
}

char* mystrcat(char *dest, char *src)
{
	char *p;
	p = dest;

	while(*dest++);
	dest--;
	while(*dest++ = *src++);
//	*dest = '\0';

	return p;
}

