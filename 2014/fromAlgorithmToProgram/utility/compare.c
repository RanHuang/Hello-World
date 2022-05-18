/*************************************************************************
	> File Name: compare.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Tue 14 Jul 2015 09:44:58 PM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include"compare.h"

int intComp(int const* x, int const* y)
{
	return (*x) - (*y);
}
int charComp(char const* x, char const* y)
{
	return (*x) - (*y);
}
int floatComp(float const* x, float const* y)
{
	if((*x - *y) > 0.0) return 1;
	if((*x - *y) < 0.0) return -1;
	return 0;
}
int doubleComp(double const* x, double const* y)
{
	if((*x - *y) > 0.0) return 1;
	if((*x - *y) < 0.0) return -1;
	return 0;
}

int unsignedComp(unsigned const* x, unsigned const* y)
{
	return (*x) - (*y);	
}

int unsignedLongLongComp(unsigned long long const* x, unsigned long long const* y)
{
	if((*x) - (*y) > 0) return 1;
	if((*x) - (*y) < 0) return -1;
	return 0;
}
