/*************************************************************************
	> File Name: system_call_sample.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月24日 星期二 09时50分29秒
  > Description:
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int status;
	if((status = system(NULL)) < 1){
		printf("system call invalid!");
		exit(0);
	}
	printf("systme(NULL) exit status: %d\n\n", status);

	if((status = system("date")) < 0){
		printf("system call invalid!");
		exit(0);
	}
	printf("systme(\"date\") exit status: %d\n\n", status);

	if((status = system("invalidcommand")) < 0){
		printf("system call invalid!");
		exit(0);
	}
	printf("systme(\"invalidcommand\") exit status: %d\n\n", status);

	if((status = system("who;exit 44")) < 0){
		printf("system call invalid!");
		exit(0);
	}
	printf("systme(\"who; exit 44\") exit status: %d\n\n", status);

	return 0;
}
