/*************************************************************************
	> File Name: runtime.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Wed 11 Nov 2015 10:46:21 AM CST
    > Description: 
		捕捉程序运行时间
		clock() CLK_TCK
 ************************************************************************/

#include <stdio.h>
#include <time.h>

clock_t start, stop;
double duration;

int main()
{
	start = clock();

	//My Function
	PrintN(1000);
	printf("\n");
	
	stop = clock();
	/**
	 * error: ‘CLK_TCK’ undeclared (first use in this function)
	 */
	duration = ((double)(stop - start))/CLK_TCK;
	printf("Program Running Duration: %.4f s\n", duration);
}

int PrintN(int n)
{
	if(n){
		printN(n - 1);
		printf("%d ", n);
	}
	
	return 0;
}
