#include <stdio.h>
#include "myfunc.h"
int main()
{
    int a[10]={4,5,3,9,10,7,2,8,6,1};
    int i,j;
    int *pi;
    MALLOC(pi,sizeof(int));

    for ( i = 0; i < 10; i++ )
    {
        *pi = a[i];
        printf("%d\t",*pi);
    }
    putchar('\n');

    for ( i = 0; i < 9; i++ )
    {
        for ( j = i+1; j < 10; j++ )
        {
            //if ( a[i] > a[j] ) swap(a+i, a+j);
            if ( a[i] < a[j] ) SWAP(a[i], a[j], *pi);
        }
    }
    //swap(a+0,a+1);
    for ( i = 0; i < 10; i++ )
    {
        printf("%d\t",a[i]);
    }
    putchar('\n');

    free(pi);
    return 0;
}
