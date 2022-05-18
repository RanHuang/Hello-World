/*************************************************************************
	> File Name: gcd.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 25 Apr 2015 08:59:06 PM CST
	> Description: 欧几里得算法求最大公约数
 ************************************************************************/

#include<stdio.h>
#include"selflib.h"

int main(int argc, char *argv[])
{
	int m, n;
	int gcd_ret;
	printf("Input two numbers: ");
	scanf("%d %d", &m, &n);
	//gcd_ret = gcdLoop(m ,n);
	gcd_ret = gcdRecursion(m ,n);
	printf("The GCD of %d and %d is: %d\n", m, n, gcd_ret);

	return 0;
}
