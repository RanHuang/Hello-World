/*************************************************************************
	> File Name: named_pipe.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Thu 30 Jul 2015 03:23:39 PM CST
    > Description: 
	命名管道:在文件系统中可见，可用于任何进程之间，以集合点模式工作。
#include<sys/types.h>
#include<sys/stat.h>
int mkfifo(const char *pathname, mode_t mode);
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

#define MAX_LINE 50

void mk_named_pipe(const char *pathname);
void read_named_pipe(const char *pathname);
void write_named_pipe(const char *pathname);

int main(int argc, char* argv[])
{
	char namedPipe[20] = "/tmp/cmd_pipe";

	mk_named_pipe(namedPipe);

	/**
	 * 进行管道读写，需要写入者打开管道一端，读取者才能打开该命名管道；
	 * 如果没有写入者，读取着的open调用会被阻断。
	 * 管道是进程间通信的有效机制。
	 */
	if(fork() == 0){
		write_named_pipe(namedPipe);
	}else{
		read_named_pipe(namedPipe);
	}

	return 0;
}
void mk_named_pipe(const char *pathname)
{
	int ret;

	ret = mkfifo(pathname, S_IFIFO | 0666);
	if(ret == 0){
		printf("Create a named pipe successfully.\n");
	} else {
		fprintf(stderr, "Named PIPE created failed: %s", strerror(errno));
		exit(1);
	}
}
void read_named_pipe(const char *pathname)
{
	FILE *pfp;
	char buffer[MAX_LINE + 1];

	pfp = fopen(pathname, "r");
	fgets(buffer, MAX_LINE, pfp);

	printf("Content read from named pipe: %s\n", buffer);
}
void write_named_pipe(const char *pathname)
{
	int ret;
	FILE *pfp;

	pfp = fopen(pathname, "w+");

	ret = fprintf(pfp, "Here's a test string!");

	printf("write a string to the named pipe.\n");
}
