/*************************************************************************
	> File Name: vfork_father_hangup.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月23日 星期一 16时58分16秒
  > Description: vfork创建的子进程导致父进程挂起
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int global_var = 100; //全局变量
int main(int argc, char *argv[])
{
	pid_t pid;
	int local_var = 10; //局部变量
	
	printf("Befor call vfork(): flag = %d, var = %d\n", global_var, local_var);

	pid = vfork(); //创建子进程
	if(pid < 0) {
		printf("Error in fork()!");
		exit(EXIT_FAILURE);
	} else if(0 == pid){
		int i;
		for(i=1; i<1000; i++){
			printf("Child Process: PID = %d, loops = %d\n", getpid(), i);
			if(i>79) exit(EXIT_SUCCESS);
		}
		printf("Child Process: PID = %d\n", getpid());
		printf("Child Process: flag = %d, var = %d\n", ++global_var, ++local_var);
		exit(EXIT_SUCCESS);
	} else {
		printf("Parent Process: PID = %d\n", getpid());
		printf("Parent Process: flag = %d, var = %d\n", global_var, local_var);
	}

	return 0;
}
