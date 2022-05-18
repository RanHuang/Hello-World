/*************************************************************************
	> File Name: ls_wc.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Thu 30 Jul 2015 03:00:23 PM CST
    > Description: 
		使用匿名管道模拟命令$ls -l | wc -l
		匿名管道仅用于进程与子进程直接通信
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	int pfds[2];
	/**
	 * pfds[0]:可读文件描述符--管道输出
	 * pfds[1]:可写文件描述符--管道输入
	 */

	if(pipe(pfds) == 0){
		if(fork() == 0){
			close(pfds[0]);
			close(1);
			/*将子进程的输出重定向到管道的输入*/
			dup2(pfds[1], 1);
			execlp("ls", "ls", "-l", NULL);
		}else{
			close(pfds[1]);
			close(0);
			/*将父进程的输入重定向到管道的输出*/
			dup2(pfds[0], 0);
			execlp("wc", "wc", "-l", NULL);
		}
	}
}
