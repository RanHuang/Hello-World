/**
 *	GNU/Linux存在两种进程类型，分别为内核线程（由kernel_thread()函数创建）和用户进程(由fork和clone函数创建)。fork对内存的复制是指向同一内存空间，并将内存页面标记为copy-on-write。
 *	ps -- ps --User nick -H
 *	top -- 实时运行，可设置显示频率
 *	kill -- 查看处理器可用信号， kill -l
 */ 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	int var = 0;
	int role = -1;
	
	pid = fork();
	/*fork返回值指明进程的上下文环境，
	 * >0， 位于父进程，指明子进程ID
	 * =0，位于子进程
	 * <0，error，位于父进程
	 */
	if(pid < 0) {
		printf("Error in fork()!");
		exit(EXIT_FAILURE);
	} else if(0 == pid){
		printf("This is a child process, pid is %d\n", getpid());
		var = 100;
		role = 0;
	} else {
		printf("This is parent process, pid is %d\n", getpid());
		var = 50;
		role = 1;
	}
	printf("var is %d\n", var);

	printf("Group ID is: %d\n", getgid());
	printf("User ID is: %d\n", getuid());

	printf("%s: Existing...\n", ((role == 0)? "Parent" : "Child"));

	return 0;
}
