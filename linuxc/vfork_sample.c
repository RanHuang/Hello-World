/*************************************************************************
	> File Name: vfork_sample.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月23日 星期一 16时48分09秒
  > Description:
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int flag = 100; //全局变量
int main(int argc, char *argv[])
{
	pid_t pid;
	int var = 0; //局部变量
	char buff[30];
	
	memset(buff, 0, sizeof(buff));

	pid = vfork(); //创建子进程
	if(pid < 0) {
		printf("Error in fork()!");
		exit(EXIT_FAILURE);
	} else if(0 == pid){
		printf("Child Process: PID = %d\n", getpid());
		printf("Child Process: flag = %d, var = %d\n", ++flag, ++var);
		strcpy(buff, "I like linuxc.");
		printf("Child Process buff:%s\n", buff);
		exit(EXIT_SUCCESS);
	} else {
		printf("Parent Process: PID = %d\n", getpid());
		printf("Parent Process: flag = %d, var = %d\n", flag, var);
		printf("Parent Process buff:%s\n", buff);
	}

	return 0;
}
