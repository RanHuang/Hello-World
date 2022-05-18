
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	int var = 0;
	
	pid = fork();
	if(pid < 0) {
		printf("Error in fork()!");
		exit(EXIT_FAILURE);
	} else if(0 == pid){
		printf("This is a child process, pid is %d\n", getpid());
		var = 100;
	} else {
		printf("This is parent process, pid is %d\n", getpid());
		var = 50;
	}
	printf("var is %d\n", var);

	return 0;
}
