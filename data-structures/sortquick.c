/*************************************************************************
	> File Name: sortquick.c
	> Author: xjhznick
	> Mail: xjhznick@163.com 
	> Created Time: 2015年03月10日 星期二 18时20分51秒
	> Description: Quit Sort (k*n*ln(n))
	  二分思想，通过一趟排序将待排序记录分为两个部分，其中一部分的记录的关键字均比另一部分的关键字小，然后递归分别对这两个整体有序的部分继续进行排序，以达到整个序列有序。
 ************************************************************************/

#include<stdio.h>

#define MAXSIZE 100

void printIntergerArray(int arr[], int n);
void QuickSort(int arr[], int low, int high);
int Partion(int arr[], int low, int high);

int main()
{
	int array[MAXSIZE],i;
	int length;
	printf("Enter the length of a array:");
	scanf("%d", &length);
	printf("Enter the elements(Interger) of the array:\n");
	for(i=0; i<length; i++)
		scanf("%d", &array[i]);

	QuickSort(array, 0, length -1);

	printf("The sorted array:\n");
	printIntergerArray(array, length);

	return 0;
}

void QuickSort(int arr[], int low, int high)
{
	int pivotLocation;
	if(low < high){
		//将待排序数组一分为二
		pivotLocation = Partion(arr, low, high);
		//递归排序两个数组，其中枢轴位置可以不用参与排序
		QuickSort(arr, low, pivotLocation-1);
		QuickSort(arr, pivotLocation+1, high);
	}
}
//从小到大进行排序
int Partion(int arr[], int low, int high)
{
	int pivot;
	int temp; 

	//选出并记录枢轴数据，同时空出一个位置用于移动数据
	pivot = arr[low]; //Make the first element of the array as the pivot.
	while(low<high){
		//小 -> 大，比枢轴小置于前，比枢轴大置于后
		while(low<high && arr[high]>=pivot) high--; //后 -> 前
		arr[low] = arr[high];
		while(low<high && arr[low]<=pivot) low ++; //前 -> 后
		arr[high]=arr[low];
	}
	arr[low]=pivot;

	return low;
}

void printIntergerArray(int arr[], int n)
{
	int i;
	printf("\t");
	for(i=1; i<=n; i++){
		printf("%d ", arr[i-1]);
		if(0 == (i%15)) printf("\n\t");
	}
	printf("\n\n");
}
