/*************************************************************************
	> File Name: josephus.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Mon 04 May 2015 08:13:47 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAXNUM 50
int main()
{
	int m, n;
	int i, pos, count;
	int josephus[MAXNUM] = {0};
	printf("Input N（人数） & M（报数）\n> ");
	scanf("%d %d", &n, &m);
	count = 0;
	pos = 0;
	while(count < n){
		i = 0;
		while(1){
			if(josephus[pos] == 0){
				i++;
			}
			if(i >= m) break;
			pos++;
			pos = pos % n;
		}
		count ++;
	//	printf("count = %d pos = %d\n", count, pos);
		josephus[pos] = count;
		pos++;
		pos = pos % n;
	}
	//
	for(i=0; i<n; ){
		printf("%2d -- %2d\t", i+1, josephus[i]);
		i++;
		if(i%5 == 0) printf("\n");
		//The last one
		if(josephus[i] >= n) pos = i+1; 
	}
	printf("\n");
	//printf("%d人按%d报数进行约瑟夫游戏，最后剩下的标号为%d\n", n, m, pos);
	printf("%d人按%d报数进行约瑟夫游戏，最后剩下的标号为%d\n", 
			n, m, jose(n, m)+1); //位置从1起计数
	return 0;
}
//数学递推方法，运算时位置标号从0起:0 ~ n-1，报数0 ~ m-1
int jose(int n, int m)
{
	int sum = 0;
	int i;
	for(i=1; i<=n; i++)
		sum = (sum + m) % i;
	return sum;
}
