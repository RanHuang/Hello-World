/*************************************************************************
	> File Name: linearSerach.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sun 05 Jul 2015 10:32:00 AM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include "search.h"
/*
int linearSearch(int *a, int len, int x)
{
	int i = 1;
	while(i <= len){
		if(a[i] == x)
			return i;
		i++;
	}
	return -1;
}
*/

int intComp(int* x, int* y)
{
	return (*x) - (*y);
}
int charComp(char* x, char* y)
{
	return (*x) - (*y);
}
int floatComp(float* x, float* y)
{
	if((*x - *y) > 0.0) return 1;
	if((*x - *y) < 0.0) return -1;
	return 0;
}
int doubleComp(double* x, double* y)
{
	if((*x - *y) > 0.0) return 1;
	if((*x - *y) < 0.0) return -1;
	return 0;
}
int main(int argc, char* argv[])
{
	int a[11] = {0, 4, 8, 56, 7, 34, 53, 23, 13, 59, 43};
	int x = 34;
	int pos;

	pos = linearSearch(a, sizeof(int), 10, &x, intComp);
	printf("Search %d, pos: %d\n", x, pos);
	
	return 0;
}
