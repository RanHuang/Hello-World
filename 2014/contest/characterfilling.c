#include<stdio.h>
#define N 300
int main()
{
	int i,j,n;
	char a[N][N];
	int b[N][N];

	char x,y;
	int countAll, countX;

	while(scanf("%d", &n) != EOF)
	{
		getchar();
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				b[i][j] = 0;
				scanf("%c", &a[i][j]);
			}
			getchar();
		}

		if(n>1)
		{
			x = a[0][0];
			y = a[0][1];
			if(x == y)
			{
				printf("NO\n");
				continue;
			}
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					if(a[i][j] == x)
					{
						b[i][j] = 1;
					} else if(a[i][j] == y){
						b[i][j] = 0;
					} else {
						b[i][j] = 300;
					}
				}
			}
			countAll = 0;
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					countAll += b[i][j];
				}
			}
			countX = 0;
			for(i=0; i<n; i++)
			{
				countX += b[i][i];
				countX += b[i][n-1-i];
			}
			if((countAll==(2*n -1)) && (countX==(2*n)))
			{
				printf("YES\n");
			}else{
				printf("NO\n");
			}

		}else{
			printf("YES\n");
		}
	}

		return 0;
}
