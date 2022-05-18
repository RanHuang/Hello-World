/*****************************************************************************
 * Author	 : Nick | work at XJTU-YLAB.
 * Email	 : xjhznick@gmail.com
 * Last modified : 2014-09-18 21:04
 * Filename	 : 2_fibonacci.c
 * Description	 : 斐波那契数列, 递归求解
 * f(n) = f(n-1) + f(n-2)
 * 1, 1, 2, 3, 5, 8, 13...
 * ***************************************************************************/
#include<stdio.h>
int fibonacci(int n)
{
	if(n<=2) return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}
int main()
{
	int n = 0;
	do {
		printf("Input the number of month(n>=1): n=");
		scanf("%d", &n);
	}while(n<1);
	if(n<3)
		printf("The total number of rabbits: 1\n");
	else
		printf("The total number of rabbits: %d\n", fibonacci(n));
	return 0;
}
