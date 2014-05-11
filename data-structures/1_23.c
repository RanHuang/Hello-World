#include <stdio.h>
#include "myfunc.h"
int main()
{
	int a[MAX_SIZE][MAX_SIZE];
	int i,j,k,col,row;
	int n_cube,n_square;
	//TODO...
	n_cube = 5;/* odd number for magic cube */
	for(i = 0; i < n_cube; i++)
	  for(j = 0;j <= i; j++)
	  {
		  a[i][j] = 0;
		  a[j][i] = 0;
	  }

	n_square = n_cube * n_cube;
	i = 0;
	j = n_cube / 2;
	a[i][j] = 1;/*Intialize the middleof the first row*/

	PRINTF("a[%d][%d] = %d\n", i, j, a[i][j]);
	for(k = 2;k <= n_square; k++)
	{
		PRINTF("a[%d][%d] = %d\n", i, j, a[i][j]);
		row = (i + n_cube - 1) % n_cube;
		col = (j + n_cube - 1) % n_cube;
		if(a[row][col]) i = (++i) % n_cube;
		else
		{
			i = row;
			j = col;
		}
		a[i][j] = k;
	}
//	printArr(a, n_cube, n_cube);	
	
	for(i = 0; i < n_cube; i++)
	{
		for(j = 0; j < n_cube; j++)
			printf("%4d  ",a[i][j]);
		printf("\n");
	}

	return 0;
}
