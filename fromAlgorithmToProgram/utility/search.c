/*************************************************************************
	> File Name: search.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sun 05 Jul 2015 11:23:26 AM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include "search.h"

int linearSearch(void *a, int size, int n, void *x, int(*comp)(void*, void*))
{
	int i = 0;
	while(i < n){
		if(comp((char*)a+i*size, x)==0)
			return i;
		i++;
	}
	return -1;
}

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
