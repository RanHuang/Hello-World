/*************************************************************************
	> File Name: test_memory.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 16 Oct 2015 02:32:26 PM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *buffer;

	buffer = (char *)malloc(5);

	strcpy(buffer, "0123456");

	printf("buffer :%s\n", buffer);

	return 0;
}
