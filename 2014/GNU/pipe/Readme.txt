管道编程API:
	#include<unistd.h>
	int pipe(int filedes[2]);
	int dup(int oldfd);
	int dup2(int oldfd, int targetfd);
	int mkfifo(const char *pathname, mode_t mode);
命令行模式下使用命名管道：
	创建命名管道：
 	$mfifo -m 0644 cmd_pipe
 	$mknod cmd_pipe p
	输入如下命令后，进程挂起，等待管道输入：
 	$cat cmd_pipe
	新开终端，向管道写入信息：
 	$echo "hello" > cmd_pipe
