/*************************************************************************
	> File Name: bubblesort.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 16 Oct 2015 09:44:24 AM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>

void bubbleSort(int list[], int size)
{
	int i, j;
	int temp;
	int swap = 1;

	while(swap){
		swap = 0;
		for(i=0; i<size; i++){
			for(j=i; j<size-1; j++){
				if(list[j] > list[j+1]){
					/* swap */
					swap = 1;
					temp = list[j];
					list[j] = list[j+1];
					list[j+1] = temp;
				}
			}
		}
	}
}

int main()
{
	int intList[10] = {10, 9, 6, 7, 5, 8, 4, 3, 2, 1};
	int i;

	bubbleSort(intList, 10);

	for(i=0; i<10; i++)
		printf("%d  ", intList[i]);

	printf("\n");

	return 0;
}
