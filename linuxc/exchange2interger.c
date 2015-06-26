/*************************************************************************
	> File Name: exchange2interger.c
	> Author: xjhznick
	> Mail: xjhznick@163.com 
	> Created Time: 2015年03月11日 星期三 13时37分54秒
  > Description:以三种不同方式交换两个整数值，数值运算、位运算(异或)、利用中间变量
 ************************************************************************/

#include<stdio.h>

void exchangeByArithmetric(int *a, int *b);
void exchangeByXor(int *a, int *b);
void exchangeByTempvalue(int *a, int *b);
int printMenu();

int main(int argc, char *argv[])
{
	int a,b;
	int select;

	while(1){
		select = printMenu();
		switch(select){
			case 1:
				printf("Enter two interger to exchange : ");
				scanf("%d %d", &a, &b);
				printf("Before exchange : a = %d, b = %d \n", a, b);
				exchangeByArithmetric(&a, &b);
				break;
			case 2:
				printf("Enter two interger to exchange : ");
				scanf("%d %d", &a, &b);
				printf("Before exchange : a = %d, b = %d \n", a, b);
				exchangeByXor(&a, &b);
				break;
			case 3:
				printf("Enter two interger to exchange : ");
				scanf("%d %d", &a, &b);
				printf("Before exchange : a = %d, b = %d \n", a, b);
				exchangeByTempvalue(&a, &b);
				break;
			default:
				return 0;
		}
		printf("After exchange  : a = %d, b = %d \n\n", a, b);
	}
}

int printMenu()
{
	int i;
	printf("Select a algorithm to exchange the two interger values:\n"
			"\t0.Exit\n"
			"\t1.Arithmetric algorithem\n"
			"\t2.Xor operation\n"
			"\t3.Use a temp value\n"
		  );
	printf("Enter the index : ");
	scanf("%d", &i);
	return i;
}

void exchangeByArithmetric(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void exchangeByXor(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void exchangeByTempvalue(int *a, int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
