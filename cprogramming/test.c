/*************************************************************************
	> File Name: test.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 25 Apr 2015 10:22:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include"selflib.h"
int main()
{
	int n;
	n = getInteger("Input");
	printf("Output = %d\n", n);
	return 0;
}
