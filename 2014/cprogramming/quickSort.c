/*************************************************************************
	> File Name: quickSort.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sun 07 Jun 2015 09:34:43 PM CST
	> Description:以整数为测试用例，实现快速排序算法
 ************************************************************************/

#include<stdio.h>
#include"selflib.h"

void quickSortS2B(int *a, int left, int right);
int main()
{
	int a[15] = {6, 1, 11, 2, 7, 15, 13, 9, 3, 14, 4, 5, 12 ,10, 8};
	int b[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	quickSortS2B(a, 0, 14);
	printInteger(a, 15, 10);

	quickSortS2B(b, 0, 9);
	printInteger(b, 10, 10);
	return 0;
}

void quickSortS2B(int *a, int left, int right)
{
	int i, j, pivot;
	if(left>=right) return;
	/*Select the pivot.*/
	pivot = (left + right)/2;
	integerSwap(&a[left], &a[pivot]);
	pivot = left;

	i = left;
	j = right;
	while(i<j){
		/*The sequence is very important. From right to left.*/
		while(a[j]>=a[pivot] && i<j) j--;
		while(a[i]<=a[pivot] && i<j) i++;
		if(i<j) 
			integerSwap(&a[i], &a[j]); 
	}
	if(a[pivot] > a[i]){
		integerSwap(&a[pivot], &a[i]);
		pivot = i;
	}

	quickSortS2B(a, left, pivot-1);
	quickSortS2B(a, pivot+1, right);
}
