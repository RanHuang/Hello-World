/*************************************************************************
	> File Name: waitpid_sample2.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月24日 星期二 09时24分01秒
  > Description:
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>
int main(int argc, char *argv[])
{
	pid_t pid_child, pid_wait;
	time_t timer;
	struct tm *tmblock;

	pid_child = fork();
	if(pid_child < 0){
		printf("fork() error!");
		exit(1);
	}else if(pid_child == 0){
		printf("Child Process: PID = %d\n", getpid());
		sleep(3);
		exit(0);
	}else{
		printf("Parent Process: PID = %d\n", getpid());
		do{
			/*使用WNOHANG参数，waitpid函数不等待立即返回*/
			pid_wait = waitpid(pid_child, NULL, WNOHANG);
			if(pid_wait == 0){
				timer = time(NULL);
				tmblock = localtime(&timer);
				printf("No child process terminated. %s", asctime(tmblock));
				sleep(1);
			}
		}while(pid_wait == 0);
		
		if(pid_wait == pid_child){
			printf("Child process terminated. PID_WAIT = %d\n", pid_wait);
		}else{
			printf("Some other error occured!\n");
		}
	}

	return 0;
}
