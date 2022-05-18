/*************************************************************************
	> File Name: strtok_r.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Thu 16 Jul 2015 08:50:01 PM CST
    > Description: 
		Reentrant, safe strtok fuction, POSIX standard.
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
	char string[254]; 
	char *string1, *string2;
	char *separator1 = "?&"; //一级分隔符
	char *separator2 = "/="; //二级分隔符
	char *saveptr1, *saveptr2;
	char *token, *subtoken;
	int i;
	
	memset(string, 0, 254*sizeof(char));
	strcpy(string, "http://www.google.com/search?complete=1&h1=zh-CN&ie=GB2312&q=linux&meta=");

	for(i=0, string1=string; ;i++, string1 = NULL){
		token = strtok_r(string1, separator1, &saveptr1);
		if(token == NULL)
			break;
		printf("%d: %s\n", i, token);

		for(string2=token; ; string2 = NULL){
			subtoken = strtok_r(string2, separator2, &saveptr2);
			if(subtoken == NULL) break;
			printf(" --> %s\n", subtoken);
		}
	}

	exit(EXIT_SUCCESS);
}
