#include <stdio.h>
#include "myfunc.h"
int binSearch(int [], int, int, int);
int binSearchRecursion(int [], int, int, int);
int main()
{
    int n,index;
    int list[MAX_SIZE_ARRAY];

	n = createTestIntArray(list);

    sortMin2max(list, n);
//    sortMax2min(list, n);

    printf("The sorted numbers:\n");
    
    printNum(list, n);

	list[40] = 1000;
	index = 9;
//	n = binSearch(list, list[index], 0, n-1);
	n = binSearchRecursion(list, list[index], 0, n-1);
	if(n > 0)
	{
		printf("The value %d is found, its positon is %d \n",
				   	list[index], index);
	} else
	  printf("%d not found in the array!\n", list[index]);

    return 0;
}

int binSearch(int list[], int searchNum, int left, int right)
{
	/*search list[0] <= list[1] <= ... <= list[n-1] for searchNum. 
	  Return its positon if found.Otherwise return -1. */
	int middle;
	while(left <= right)
	{
		middle = (left + right) / 2;
		switch ( COMPARE(list[middle], searchNum) )
		{
			case -1 : left = middle + 1;
					  break;
			case 0  : return middle;
			case 1  : right = middle -1;
		}
	}
	return -1;
}

int binSearchRecursion(int list[], int searchNum, int left, int right)
{
	int middle;
	PRINTF("Goto the recursive binary search fucntion.\n");
	if(left <= right)
	{
		middle = (left + right) / 2;

		switch(COMPARE(list[middle], searchNum))
		{
			case -1 : return binSearchRecursion(list, searchNum, 
								                middle + 1, right);
			case  0 : return middle;
			case  1 : return binSearchRecursion(list, searchNum,
								  				left, middle - 1);
		}
	}
	return -1;

}
