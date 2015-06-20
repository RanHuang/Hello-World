/*************************************************************************
	> File Name: malloc_max_size.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月21日 星期六 14时43分39秒
  > Description:判断系统所能分配的最大内存空间
    Warning: 该程序无法给出最终输出，系统死机
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	void *p;
	int count = 0;
	while((p = malloc(100*1024*1024))){
		count++;
		printf("%d\n", count);
	}
	printf("\t The max size of the malloc %d00MB\n", count);
	free(p);
	return 0;
}
