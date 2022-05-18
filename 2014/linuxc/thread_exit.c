/*************************************************************************
	> File Name: thread_create.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月24日 星期二 14时53分17秒
  > Description:pthread_exit, 终止调用该函数的线程
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

char buff[] = "Hello, Linux.";

void thread_function(void *arg)
{
	pthread_t newthid;
	newthid = pthread_self();
	printf("New thread, thread ID = %lu, argument is: %s\n",
			                        newthid, (char*)arg);
	strcpy(buff, "Bye!");
	pthread_exit("I like Linux OS.");
}

int main(int argc, char *argv[])
{
	int ret;
	pthread_t thid;
	void *thread_result;

	printf("Main thread, ID = %lu\n", pthread_self());
	//create a new thread
	ret = pthread_create(&thid, NULL, (void*)&thread_function, (void*)buff);
	if(ret != 0){
		printf("Error pthread_create()!");
		exit(EXIT_FAILURE);
	}
	printf("In Main thread, buff content : %s\n", buff);
	//阻塞，等待线程thid返回
	ret = pthread_join(thid, &thread_result);
	if(ret != 0 )
	{
		printf("Error pthread_join()!");
		exit(EXIT_FAILURE);
	}

	printf("In Main thread, new thread ID = %lu\n", thid);
	//thread_result 的内容为pthread_exit函数参数指向的对象内容
	printf("In main thread, the return of join : %s\n", (char *)thread_result);
	printf("After the new thread returned, buff content : %s\n", buff);

	return 0;
}
