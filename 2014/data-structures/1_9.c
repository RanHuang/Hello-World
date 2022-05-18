#include <stdio.h>
#include "myfunc.h"
void perm(char [], int, int);
int main()
{
	int i,n;
	n = 4;
	char list[10] = {'a', 'b', 'c', 'd'};
	
	for( i = 0; i < n; i++)
	  printf("%c  ", list[i]);
	putchar('\n');
	putchar('\n');

	perm(list, 0, n-1);

	return 0;
}

void perm(char list[], int m, int n)
{
	int i,tmp;
	static int k = 0;
	if( m == n)
	{
		k++;
	  	for( i = 0; i <= n; i++)
			printf("%c  ", list[i]);
		printf(" %d\n", k);
	}
	else{
		/* list[m] to list[n] has more than one permutation, 
		 generate this recursively.*/
		for( i = m; i <= n; i++)
		{
			SWAP(list[m], list[i], tmp);
			perm(list, m+1, n);
			SWAP(list[m], list[i], tmp);
		}
	}
}
