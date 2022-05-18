/*************************************************************************
	> File Name: exec_sample.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月23日 星期一 21时33分11秒
  > Description:
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	char *envp[] = {"PATH=/home", "USER=nick", "STATUS=testing", NULL};
	char *argv_execv[] = {"echo", "Excuted by execv", NULL};
	char *argv_execvp[] = {"ls" , "Excuted by execvp", NULL};
	char *argv_execve[] = {"env", NULL};

	int ret = 0;
	if(0 == fork()){
		if(-1 == (ret = execl("/bin/echo", "echo", 
						"Excuted by execl", NULL))){
			perror("Error in execl");
		}
	}

	if(0 == fork()){
		if(-1 == (ret = execlp("echo", "echo", 
						"Excuted by execlp", NULL))){
			perror("Error in execlp");
		}
	}

	if(0 == fork()){
		if(-1 == (ret = execle("/usr/bin/env", "env", 
						 NULL, envp))){
			perror("Error in execle");
		}
	}

	if(0 == fork()){
		if(-1 == (ret = execv("/bin/echo", argv_execv))){
			perror("Error in execv");
		}
	}

	if(0 == fork()){
		if(-1 == (ret = execvp("echo", argv_execvp))){
			perror("Error in execvp");
		}
	}

	if(0 == fork()){
		if(-1 == (ret = execve("/usr/bin/env", argv_execve, envp))){
			perror("Error in execve");
		}
	}
	
	return 0;
}
