/*************************************************************************
	> File Name: bubblesort.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 16 Oct 2015 09:44:24 AM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>

#define MAX_ELEMENTS 10000

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

void insertSort(int list[], int size)
{
	int i, j;
	int temp;

	for(i=1; i<size; i++){
		temp = list[i];
		for(j=i-1; j>=0 && (list[j]>temp); j--){
			list[j+1] = list[j];
		}
		list[j+1] = temp;
	}
}

void initList(int list[], int size)
{
	int i;
	for(i=0; i<size; i++){
		list[i] = size - i;
	}
	return;
}
int main()
{
	int int_list[MAX_ELEMENTS];
	int size = 5000;

	initList(int_list, size);
	insertSort(int_list, size);

	initList(int_list,  size);
	bubbleSort(int_list, size);

	//printf("%d %d\n", int_list[0], int_list[size-1]);

	return 0;
}
