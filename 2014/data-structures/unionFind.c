/*************************************************************************
	> File Name: unionFind.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 27 Jun 2015 08:18:31 PM CST
	> Description: 简单的并查集操作
 ************************************************************************/

#include<stdio.h>
#define MAXSIZE 1001

void init(int* array, int n);
int getRoot(int* array, int alice);
void merge(int* array, int alice, int bob);

int main(int argc, char* argv[])
{	
	int arr[MAXSIZE];
	int relationship[10][2] = {{0, 0},
		{1, 2}, {3, 4}, {5, 2}, {4, 6}, {2, 6},
		{8, 7}, {9, 7}, {1, 6}, {2, 4}};
	int n, m;
	int i, count;
	puts("Input the number of elements and relationships(m n):");
	//scanf("%d %d", &m, &n);

	m = 10, n = 9;
	//初始化
	init(arr, m);
	//开始合并操作
	for(i=1; i<=n; i++){
		printf("Merge:%d %d\n", relationship[i][0], relationship[i][1]);
		merge(arr, relationship[i][0], relationship[i][1]);
	}
	//确定分组个数
	for(i=1, count=0; i<=m; i++){
		if(arr[i] == i){
			count++;
		}
	}

	printf("The total number of sets is %d\n", count);

	return 0;
}


void init(int* array, int n)
{
	int i;
	for(i=0; i<=n; i++){
		array[i] = i;
	}
	return;
}
int getRoot(int* array, int alice)
{
	if(array[alice] == alice) return alice;
	array[alice] = getRoot(array, array[alice]);
	return array[alice];
}
void merge(int* array, int alice, int bob)
{
	int rootA, rootB;
	rootA = getRoot(array, alice);
	rootB = getRoot(array, bob);

	if(rootA != rootB){
		array[rootB] = rootA;
	}
	 
	return;
}
