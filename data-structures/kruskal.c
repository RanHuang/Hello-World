/*************************************************************************
	> File Name: kruskal.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 27 Jun 2015 09:06:10 PM CST
	> 克鲁斯卡尔算法--最小生成树
	1.将边按照权值从小到大排序；
	2.依次选择排好序的边，根据并查集进行最小生成树的构造
 ************************************************************************/

#include<stdio.h>
typedef struct edge{
	int u; //begin vertex
	int v; //end vertex
	int w; //weight of edge
}Edge;


void init(int* array, int n);
int getRoot(int* array, int alice);
int merge(int* array, int alice, int bob);
void quickSort(Edge* arr, int left, int right);
void testEdgeArr(Edge* arr, int n);

int main(int argc, char* argv[])
{
	//测试集，6个顶点，9条边
	Edge edge_arr[10] = {{0}, {2, 4, 11}, {3, 5, 13}, {4, 6, 3}, {5, 6, 4},
		{2, 3, 6}, {4, 5, 7}, {1, 2, 1}, {3, 4, 9}, {1, 3, 2}};
	int edge_root[10] = {0};
	int m, n;
	int i, count_edge;
	int sum_weight;

	m = 6, n = 9;
	init(edge_root, n);

//	testEdgeArr(edge_arr, n);

	quickSort(edge_arr, 1, n); //根据权值从小到大排序

	sum_weight = 0;
	for(i=1, count_edge=0; i<=n; i++){
		if(merge(edge_root, edge_arr[i].u, edge_arr[i].v)){
			count_edge++;
			sum_weight += edge_arr[i].w;
		}
		if(count_edge >= n-1) break; //生成树边为 n-1，提前结束
	}
	printf("Minimum Spanning Tree: Edge - %d, Sum of Wight - %d\n", count_edge, sum_weight);

	return 0;
}

void testEdgeArr(Edge* arr, int n)
{
	int i;
	for(i=1; i<=n; i++){
		arr[i].w = n-i;
	}
}
//使用快速排序算法，根据权值从小到大排列这些边
void quickSort(Edge* arr, int left, int right)
{
	int l,r;
	Edge temp;

	if(left >= right) return;

	//基准数为arr[left]
	l = left, r = right;
	while(l < r){
		while(arr[r].w >= arr[left].w && l<r) r--;
		while(arr[l].w <= arr[left].w && l<r) l++;
		if(l < r){
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}
	}
	temp = arr[left];
	arr[left] = arr[l];
	arr[l] = temp;

	quickSort(arr, left, l - 1);
	quickSort(arr, l + 1, right);
	return ;
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
int  merge(int* array, int alice, int bob)
{
	int rootA, rootB;
	rootA = getRoot(array, alice);
	rootB = getRoot(array, bob);

	if(rootA != rootB){
		array[rootB] = rootA;
		return 1;
	}
	 
	return 0;
}
