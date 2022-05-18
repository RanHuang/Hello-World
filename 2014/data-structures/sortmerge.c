/*************************************************************************
	> File Name: sortmerge.c
	> Author: xjhznick
	> Mail: xjhznick@163.com 
	> Created Time: 2015年03月10日 星期二 19时19分15秒
	> Description:将待排序数组以二分法递归分为两个部分(二叉树)，最后从叶子数组开始合并，并保证两个字节点合并为父节点后父数组有序(合并时排序)
 ************************************************************************/

#include<stdio.h>

#define MAXSIZE 10

void printIntergerArray(int arr[], int n);
void MergeSort(int arr[], int begin, int end);
void Merge(int arr[], int begin, int mid, int end);

int main()
{
	int array[MAXSIZE],i;
	int length;
	printf("Enter the length of a array:");
	scanf("%d", &length);
	printf("Enter the elements(Interger) of the array:\n");
	for(i=0; i<length; i++)
		scanf("%d", &array[i]);

	MergeSort(array, 0, length - 1);

	printf("The sorted array:\n");
	printIntergerArray(array, length);

	return 0;
}

void MergeSort(int arr[], int begin, int end)
{
	int mid;

	if(begin < end){
		mid = (begin+end)/2;
		//二分法分解待排序数组为两部分,然后合并时排序
		MergeSort(arr, begin, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, begin, mid, end);
	}
}

void Merge(int arr[], int begin, int mid, int end)
{
	int	i, length, li, ri;
	int lLen, rLen;
	int LeftArr[MAXSIZE], RightArr[MAXSIZE];

	lLen=mid-begin+1, rLen=end-mid;
	//待排序的两个子数组
	for(i=0; i<lLen; i++){
		LeftArr[i] = arr[begin+i];
	}
	for(i=0; i<rLen; i++){
		RightArr[i] = arr[mid+1+i];
	}
	
	i = 0,li = 0, ri = 0;
	//小->大:归并时，依次比较并取取两个数组中较小元素置于原数组前面
	while(li<lLen && ri<rLen){
		if(RightArr[ri] < LeftArr[li]){
			arr[begin+i] = RightArr[ri];
			ri++;
		} else {
			arr[begin+i] = LeftArr[li];
			li++;
		}
		i++;
	}
	while(li<lLen) arr[begin + i++] = LeftArr[li++];
	while(ri<rLen) arr[begin + i++] = RightArr[ri++];
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
