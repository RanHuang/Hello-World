/*************************************************************************
	> File Name: dynamic_gdb.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 16 Oct 2015 03:36:03 PM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int counter = 0;

int main()
{
	while(1){
		sleep(1);
		counter++;
	}

	return 0;
}
