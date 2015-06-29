/*************************************************************************
	> File Name: prim_heap.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sun 28 Jun 2015 10:33:00 AM CST
	> Description: 使用堆排序实现最小生成树Prim算法，降低算法时间复杂度
 ************************************************************************/

#include<stdio.h>

#define INF 99999

typedef struct edge{
	int u; //begin vertex
	int v; //end vertex
	int w; //weight of edge
}Edge;

int main(int argc, char* argv[])
{
	//测试集，6个顶点，9条边
	Edge edge_arr[10] = {{0}, {2, 4, 11}, {3, 5, 13}, {4, 6, 3}, {5, 6, 4},
		{2, 3, 6}, {4, 5, 7}, {1, 2, 1}, {3, 4, 9}, {1, 3, 2}};
	int vertex_book[7] = {0};
	int distance[7];
	int v, e, count, sum;

	int i, j, k, min;
	//初始化邻接表
	v = 6, e = 9;

	return 0;
}
