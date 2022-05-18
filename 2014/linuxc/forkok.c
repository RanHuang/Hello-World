/**
 * 以下是 fork() 的一种常规使用方式，可以将它作为一个多进程开发的框架.
 */
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define PROC_COUNT 3

int create_process(pid_t *pid, int (*proc)(void *arg), void *arg)
{
	pid_t fpid;
	int exit_code;

	fpid = fork();
	switch(fpid) {
		case 0:
			exit_code = proc(arg);
			exit(exit_code);
		case -1:
			return errno;
		default:
			*pid = fpid;
	}
	return 0;
}
int child_process(void *arg)
{
	int i;
	for(i = 0; i < 10; i++) {
		printf("process %ld, i=%d.\n", (long)arg, i);
		sleep(1);
	}
	return 0;
}
int main(int argc, char *argv)
{
	long i;
	pid_t pid[PROC_COUNT], fpid;
	int status;

	for(i = 0; i < PROC_COUNT; i++) {
		create_process(&pid[i], child_process, (void*)i);
	}

	while(1) {
		fpid = waitpid(-1, status, WNOHANG);

		if(0 == fpid) {
			sleep(1);
			continue;
		}

		for(i = 0; i < PROC_COUNT; i++) {
			if(fpid == pid[i]) {
				create_process(&pid[i], child_process, (void*)i);
			}
		}
	}

	return 0;
}
