/*************************************************************************
	> File Name: pi.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Tue 05 May 2015 08:51:05 AM CST
	> Description: 概率方法求PI
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	double x, y;
	int i, n, count;
	printf("Input the number of experiments:\n> ");
	scanf("%d", &n);
	count = 0;
	srand(time(NULL));
	for(i=0; i<n; i++){
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		if(x*x + y*y <= 1.0) count++;
	}

	printf("The estimated value of PI is: %f\n", count*4.0/n);

	return 0;
}

