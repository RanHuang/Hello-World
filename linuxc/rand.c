/*************************************************************************
	> File Name: rand.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月22日 星期日 08时39分12秒
  > Description:
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int j, r, nloops;
	unsigned int seed;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <seed> <nloops>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
				
	seed = atoi(argv[1]);
	nloops = atoi(argv[2]);
						
	srand(seed);
	//srand((unsigned int)time(NULL));
	//srand(getpid());
	//通常使用getpid或者time函数返回值作为seed
	for (j = 0; j < nloops; j++) {
		r =  rand();
		//rand()%(Y-X+1)+X; //返回[X,Y]区间的随机数
		printf("%d\n", r);
	}
								
		exit(EXIT_SUCCESS);
}
