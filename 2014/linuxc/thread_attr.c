/*************************************************************************
	> File Name: thread_create.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月24日 星期二 15时23分17秒
  > Description: 设置线程属性，创建一个脱离线程
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

const char message[] = "Hello, Linux.";
int thread_finished = 0;

void thread_function(void *arg)
{
	pthread_t newthid;
	newthid = pthread_self();
	printf("New thread, thread ID = %lu, argument is: %s\n",
			                        newthid, (char*)arg);
	sleep(3);
	printf("New thread sets thread_finished flag and exits.\n");
	thread_finished = 1;
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	int ret;
	pthread_t thid;
	pthread_attr_t attr;

	ret = pthread_attr_init(&attr);
	if(ret != 0){
		printf("Error pthread_attr_init()!");
		exit(EXIT_FAILURE); //线程属性初始化出错退出
	}

	ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(ret != 0){
		printf("Error pthread_attr_setdetachstate()!");
		exit(EXIT_FAILURE); //线程分离属性设置出错退出
	}

	//create a new thread
	ret = pthread_create(&thid, &attr, (void*)&thread_function, (void*)message);
	if(ret != 0){
		printf("Error pthread_create()!");
		exit(EXIT_FAILURE);
	}
	//销毁线程属性结构,它在重新初始化之前不能重新使用
	pthread_attr_destroy(&attr);
	while(!thread_finished){
		printf("Main thread, waiting for other thread finished...\n");
		sleep(1);
	}
	printf("Other thread fiinshed. Bye!\n"); 

	return 0;
}
