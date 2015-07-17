/*************************************************************************
	> File Name: fgetc_fputc.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 17 Jul 2015 10:23:19 AM CST
    > Description: 
		终端输入，表示文件结束的方法：
		1. 某行开头 Ctrl+D
		2. 光标不在行首 连续两次 Ctrl+D
		3. Shell Heredoc语法
			$./a.out <<ENDL
			>...
			>...
			>ENDL
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(int argc, char* argv[])
{
	FILE *fp;
	int ch;

	fp = fopen("output.dat", "w+");
	if(!fp){
		fprintf(stderr, "%s, line %d: %s\n", __FILE__, __LINE__, strerror(errno));
		return 1;	
	}

	printf("Read from stdin, write to file:\n");
	while((ch = fgetc(stdin)) != EOF)
		fputc(ch, fp);

	rewind(fp);

	printf("Read from file, write to stdout:\n");
	while((ch = fgetc(fp)) != EOF)
		fputc(ch, stdout);

	fclose(fp);

	/* 判断getchar的阻塞执行情况
	 * getchar一直阻塞到用户输入回车才返回
	 */
	/*
	while((ch = getchar()) != EOF)
		putchar(ch);
	*/
	return 0;
}
