/*************************************************************************
	> File Name: drand48.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月22日 星期日 08时57分01秒
  > Description:产生浮点数随机数
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[])
{
	int i, nloops;
	unsigned short xsubi[3];

	if(2 != argc){
		fprintf(stderr, "Usage : %s <nloops>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for(i=0 ; i<3; i++){
		xsubi[i] = (unsigned short)time(NULL);
	}

	nloops = atoi(argv[1]);
	for(i=0; i<nloops; i++){
		printf("%f ", erand48(xsubi));
	}
	printf("\n");

	exit(EXIT_SUCCESS);
}
