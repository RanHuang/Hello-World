/*************************************************************************
	> File Name: sys_err.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 17 Jul 2015 09:21:36 PM CST
    > Description: 
	格式化打印错误信息 err_sys 函数
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<stdarg.h>
#include<string.h>

#define MAXLINE 80
void err_sys(const char *fmt, ...)
{
	int err = errno, n;
	char buffer[MAXLINE+1];
	va_list ap;

	va_start(ap, fmt);

	vsnprintf(buffer, MAXLINE, fmt, ap);
	n = strlen(buffer);
	snprintf(buffer+n, MAXLINE-n, ":%s", strerror(err));
	strcat(buffer, "\n");
	fputs(buffer, stderr);

	va_end(ap);
	exit(1);
}

int main(int argc, char* argv[])
{
	FILE *fp;
	if(argc != 2){
		fputs("Usage: ./a.out pathname\n", stderr);
		exit(1);
	}

	fp = fopen(argv[1], "r");

	if(fp == NULL){
		err_sys("%s, line %d - open file %s", 
				__FILE__,__LINE__, argv[1]);
	}
	printf("Open %s OK\n", argv[1]);
	fclose(fp);
	return 0;
}
