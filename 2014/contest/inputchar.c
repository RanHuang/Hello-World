/*****************************************************************************
 * Author	 : Nick | work at XJTU-YLAB.
 * Email	 : xjhznick@gmail.com
 * Last modified : 2014-11-05 11:16
 * Filename	 : inputchar.c
 * Description	 : 
 * ***************************************************************************/
#include <stdio.h>
#define N 300
int main()
{
	int n;
	int i,j;
	char a[N][N];

	while(scanf("%d", &n) != EOF)
	{
		getchar();
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				a[i][j] = '*';
			//	a[i][j] = getchar();
				scanf("%c", &a[i][j]);
			}
			getchar();
		}
		printf("(^^)End\n");

		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				putchar(a[i][j]);
			}
			putchar('\n');
		}
		printf("(^^)End\n");
	}

	return 0;
}
