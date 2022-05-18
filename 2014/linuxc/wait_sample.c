/*************************************************************************
	> File Name: wait_sample.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月24日 星期二 08时25分52秒
  > Description:
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
	pid_t pid_child, pid_wait;
	int status,i;
	pid_child = fork();
	if(pid_child < 0){
		printf("Error in fork()!");
		exit(EXIT_FAILURE);
	}else if(pid_child == 0){
		printf("This is the child process. PID =%d\n", getpid());
		exit(55);
	}else{
		sleep(3);
		printf("This is the parent process ,wait for child...\n");

		pid_wait = wait(&status);
		i=WEXITSTATUS(status);
		printf("Child PID = %d, exit status = %d\n", pid_wait, i);
	}	
	exit(0);
}
