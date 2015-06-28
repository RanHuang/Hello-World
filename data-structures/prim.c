/*************************************************************************
	> File Name: prim.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sun 28 Jun 2015 09:40:49 AM CST
	> Description: 最小生成树 Prim 算法
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
	int edge_matrix[7][7] = {0};
	int v, e, sum;

	int i, j, k, min;
	//初始化邻接矩阵
	v = 6, e = 9;
	for(i=1; i<=v; i++){
		for(j=1; j<=v; j++){
			if(i == j) edge_matrix[i][j] = 0;
			else edge_matrix[i][j] = INF;
		}
	}
	//向邻接矩阵中填入边的信息
	for(i=1; i<=e; i++){
		//无向图，邻接矩阵对称
		edge_matrix[edge_arr[i].u][edge_arr[i].v] = edge_arr[i].w;
		edge_matrix[edge_arr[i].v][edge_arr[i].u] = edge_arr[i].w;
	
	}
	//选择1号顶点加入生成树
	vertex_book[1] = 1;
	//初始化distance数组
	for(i=1; i<=v; i++) {
		distance[i] = edge_matrix[1][i];
	}

	sum = 0;
	/**
	 * 该算法的时间复杂度为O(n^2)；因为从剩余顶点中选择加入生成树的合适顶点
	 * 时，反复扫描所有顶点O(n)
	 */
	for(i=2; i<=v; i++){ //依次从剩下的顶点中选择一个合适的顶点加入生成树
		min = INF;
		for(j=1; j<=v; j++){
			//从剩余顶点中选择到已经构造的生成树任意顶点距离最短的vertex
			if(vertex_book[j] == 0 && min > distance[j]){
				min = distance[j];
				k = j;
			}
		}
		vertex_book[k] = 1;
		sum += min;
		printf("v - %d ; min - %d \n", k, min);
		//更新distance数组
		for(j=1; j<=v; j++){
			if(vertex_book[j] == 0 && distance[j] > edge_matrix[j][k])
				distance[j] = edge_matrix[j][k];
		}
	}

	printf("Total weight of the Minimum Spanning Tree %d\n", sum);

	return 0;
}
