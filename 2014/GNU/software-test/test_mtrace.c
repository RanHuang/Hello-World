/*************************************************************************
	> File Name: test_mtrace.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 16 Oct 2015 02:54:31 PM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<mcheck.h>

int main()
{
	char *buffer;

	mtrace();

	buffer = (char *) malloc(50);

	return 0;
}
