/*************************************************************************
	> File Name: exit_differ.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月24日 星期二 07时58分53秒
  > Description:比较exit()和_exit()区别
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, char* argv[])
{
	pid_t pid;
	pid = fork();
	if(-1 == pid){
		perror("Error: fork() failure.");
		exit(EXIT_FAILURE);
	}else if(0 == pid){
		printf("Child Process: %d\n", getpid());
		printf("Child Process: Can you see me?");
		_exit(0);
	}else{
		printf("Parent Process: %d\n", getpid());
		printf("Parent Process: Can you see me?");
		exit(0);
	}
	printf("This will not be showed!\n");
	return 0;
}
