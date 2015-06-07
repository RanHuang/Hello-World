/*************************************************************************
	> File Name: hanoi.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sun 26 Apr 2015 08:04:53 AM CST
	> Description: 递归求解汉诺塔问题
 ************************************************************************/

#include<stdio.h>
int hanoi(int n, char a, char b, char c);
void oneMove(int n, char a, char b);

int main()
{
	int n;
	printf("Input the number of disk.\n >>");
	scanf("%d", &n);

	hanoi(n, 'A', 'B', 'C');

	return 0;
}

int hanoi(int n, char a, char b, char c)
{
	if(n<=1){ 
		oneMove(n, a, c);
	} else{
		hanoi(n-1, a, c, b);
		oneMove(n, a, c);
		hanoi(n-1, b, a, c);
	}
	return 0;
}
void oneMove(int n, char a, char b)
{
	printf("Index %-4d:  %c --> %c\n", n, a, b);
}

