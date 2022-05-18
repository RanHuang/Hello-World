/*****************************************************************************
 * Author	 : Nick | work at XJTU-YLAB.
 * Email	 : xjhznick@gmail.com
 * Last modified : 2014-09-15 20:51
 * Filename	 : 1_hanoi.c
 * Description	 : The towers of Hanoi. 
 * 算法分析: 采用递归算法，每次先将上面 n-1 个盘子搬到中转pag上，然后将剩下的最大
 * 的那个盘子搬到目标pag，最后将中转pag上的 n-1 个盘子搬到目标pag上。
 * hanoi() 参数设置： n 需要搬动的盘子个数； a 初始pag； b 中转pag; c 目标pag.
 * ***************************************************************************/
#include<stdio.h>
void hanoi(int n, char a, char b, char c)
{
	if(n == 1)
	{
		printf("%c --> %c %d\n", a, c, n);
		return;
	}
	hanoi(n-1, a, c, b);
	printf("%c --> %c %d\n", a, c, n);
	hanoi(n-1, b, a, c);
}

int main()
{
	int n = 0;
	do{
		printf("Input the number of the plates(1-10):");
		scanf("%d",&n);
	}while(n<=0 || n>10);
	hanoi(n, '1', '2', '3');
	return 0;
}
