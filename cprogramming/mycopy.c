/*************************************************************************
	> File Name: mycopy.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 17 Jul 2015 10:50:22 AM CST
    > Description: 
		文件复制命令copy 的模拟实现
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	FILE *fsrc, *fdest;
	int ch;

	if(argc != 3){
		fprintf(stderr, "%s, line %d: Usage - %s src dest\n", __FILE__, __LINE__, argv[0]);
		exit(1);
	}

	if((fsrc = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "%s, line %d: %s\n", __FILE__, __LINE__, strerror(errno));
		exit(1);
	}
	if((fdest = fopen(argv[2], "w+")) == NULL){
		fprintf(stderr, "%s, line %d: %s\n", __FILE__, __LINE__, strerror(errno));
		exit(1);
	}
	/*Copy character from src to dest.*/
	while((ch = getc(fsrc)) != EOF)
		putc(ch, fdest);

	return 0;
}
