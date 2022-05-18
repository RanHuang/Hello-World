#include <stdio.h>
#include "myfunc.h"
int main()
{
    int i,j,n;
    int min,temp;
    int list[MAX_SIZE_ARRAY];

	n = createTestIntArray(list);

    sortMin2max(list, n);
//    sortMax2min(list, n);

    printf("The sorted numbers:\n");
    
    printNum(list, n);

    return 0;
}

