/*************************************************************************
	> File Name: selflib.h
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 25 Apr 2015 09:06:32 PM CST
 ************************************************************************/
#ifndef SELFLIB_H
#define SELFLIB_H

#include<stdio.h>
int getInteger(char *str);
double getDouble(char *str);

void integerSwap(int *m, int *n);
int gcdLoop(int m, int n);
int gcdRecursion(int m, int n);

int getInteger(char *str)
{
	int n;
	printf("%s\n> ", str);
	scanf("%d", &n);
	return n;
}
double getDouble(char *str)
{
	double n;
	printf("%s\n> ", str);
	scanf("%lf", &n);
	/*
	 *C语言中：
	 * scanf 输入 double 类型变量时，占位符需用 %lf
	 * printf 输出时 %lf or %f 皆可
	 */
	return n;
}
void integerSwap(int *m, int *n)
{
	int temp;
	temp = *m;
	*m = *n;
	*n = temp;
}
int gcdLoop(int m, int n)
{
	int r;
	if(m<n) integerSwap(&m, &n);
	while( r = m%n ){
		m = n;
		n = r;
	}
	return n;
}
int gcdRecursion(int m, int n)
{
	int r;
	if(m<n) integerSwap(&m, &n);
	r = m%n;
	if(r==0) return n;
	else return gcdRecursion(n, r);
}

#endif
