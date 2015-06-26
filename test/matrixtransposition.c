/*************************************************************************
	> File Name: matrixtransposition.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月16日 星期一 15时02分22秒
  > Description: 修改MATSIZE 512 513 比较 执行时间，发现513时执行时间比512时更短。
 ************************************************************************/

#include<stdio.h>

#define SAMPLES 1000
#define MATSIZE 512

void transpose(int mat[][MATSIZE])
{
	int i,j,aux;
	for ( i = 0 ; i < MATSIZE ; i++ )
		for ( j = 0 ; j < MATSIZE ; j++ )
		{
			int aux = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = aux;
		}
}

int main()
{
	int i,j;
	int mat[MATSIZE][MATSIZE];
	for ( i = 0 ; i < MATSIZE ; i++ )
		for ( j = 0 ; j < MATSIZE ; j++ )
			mat[i][j] = i+j;
   
	for ( i = 0 ; i < SAMPLES ; i++ )
		transpose(mat);

	return 0;
}

