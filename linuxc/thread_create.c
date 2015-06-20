/*************************************************************************
	> File Name: thread_create.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月24日 星期二 14时23分17秒
  > Description:创建线程
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int *thread_function(void *arg)
{
	pthread_t newthid;
	newthid = pthread_self();
	printf("New thread, thread ID = %lu\n", newthid);
	return NULL;
}
int main(int argc, char *argv[])
{
	int ret;
	pthread_t thid;
	printf("Main thread, ID = %lu\n", pthread_self());
	//create a new thread
	ret = pthread_create(&thid, NULL, (void*)thread_function, NULL);
	if(ret != 0){
		printf("Error pthread_create()!");
		exit(EXIT_FAILURE);
	}

	printf("In Main thread, new thread ID = %lu\n", thid);
	sleep(1);

	return 0;
}
