#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	pid_t pid;

	while(1){
		pid = fork();
		if(0 == pid){
			printf("This is a child process, pid is %d\n", getpid());
			exit(0);
		} else {
			sleep(5);
		}
	}

	return 0;
}
