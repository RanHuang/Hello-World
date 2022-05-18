#ifndef MYFUNC_H
#define MYFUNC_H
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 1
#if DEBUG
#define PRINTF(...) printf(__VA_ARGS__)
#else 
#define PRINTF(...)
#endif
#define MAX_SIZE 20
void swap(int *x, int *y)
{/*Both parameters are pointers to ints.*/
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )
/* Example: 
   MALLOC(pi, sizeof(int));
 */
#define MALLOC(p,s)\
    if (!((p) = malloc(s))) {\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    }

void sortMin2max(int list[], int n)
{        
    int i,j;
    int min,temp;
    for ( i = 0; i < n-1; i++)
    {
        min = i;
        for ( j = i+1; j < n; j++ )
        {
            if( list[min] > list[j] ) 
              min = j;
        }
        SWAP(list[i], list[min], temp);
    }
}
void sortMax2min(int list[], int n)
{        
    int i,j;
    int max,temp;
    for ( i = 0; i < n-1; i++)
    {
        max = i;
        for ( j = i+1; j < n; j++ )
        {
            if( list[max] < list[j] ) 
              max = j;
        }
        SWAP(list[i], list[max], temp);
    }
}
/*Print n values in list[0...n-1]*/
void printNum( int list[], int n)
{
    int i;
    for ( i = 0; i < n; i++ )
    {
        printf("%d  ", list[i]);
    }
    putchar('\n');
}
#define MAX_SIZE_ARRAY 101
int createTestIntArray(int list[])
{
	int i,n;

    printf("Input the number of the numbers: ");
    scanf("%d",&n);
    if( n < 1 || n > MAX_SIZE_ARRAY )
    {
        fprintf(stderr, "Improper value of n(<=101)\n");
        exit( EXIT_FAILURE );
    }

    for ( i = 0; i < n; i++ )
    {
        list[i] = rand() % 1000;
        printf("%d  ", list[i]);
    }
    putchar('\n');

	return n;
}
int compare(int x, int y)
{/* if x> y, then return 1 */
	if( x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}
#define COMPARE(x,y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1 )
#endif
