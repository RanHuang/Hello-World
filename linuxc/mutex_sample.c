/*************************************************************************
	> File Name: mutex_sample.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月24日 星期二 19时37分21秒
  > Description:
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

#define THREAD_NUM 3
#define REPEAT_TIMES 5
#define INTERVAL 4

pthread_mutex_t mutex;
void *thread_func(void *arg);

int main(int argc, char *argv[])
{
	pthread_t thread[THREAD_NUM];
	int num, index[3];
	void *result;

	srand((int)time(NULL));
	//创建快速互斥锁，属性默认
	pthread_mutex_init(&mutex, NULL);
	/*Create THREAD_NUM threads. Thread ID <= thread[num]. The function of all threads is thread_func, and the argument is num.
	 */
	for(num=0; num<THREAD_NUM; num++){
		index[num] = num;
		if(0 != pthread_create(&thread[num], NULL, thread_func, (void*)(index+num))){
			printf("Error pthread_create:%d\n",num);
			exit(1);
		}
		printf("Succes create thread: %d\n", num);
	}
	/*
	 *thread join, the return value <= result
	 */
	for(num=0; num<THREAD_NUM; num++){
		if(0 != pthread_join(thread[num], &result)){
			printf("Error thread_join:%d\n", num);
			exit(1);
		}
		printf("Join thread success:%d\n", num);
	}
	
	//destroy the mutex
	pthread_mutex_destroy(&mutex);

	return 0;
}

void *thread_func(void *arg)
{
	int thread_num; 
	int delay_time, count;

	thread_num = *((int*)arg); //thread index, not the ID

	if(0 != pthread_mutex_lock(&mutex)){
		printf("Error mutex lock failed in thread : %d\n", thread_num);
		pthread_exit(NULL);
	} 
	//The begining of critical section.
	printf("Thread %d is running.\n", thread_num);
	for(count=0; count<REPEAT_TIMES; count++){
		// random value in [1,4]
		delay_time = rand()%INTERVAL + 1;
		sleep(delay_time);
		printf("\tThread %d: task %d delay %d.\n", thread_num, count, delay_time);
	}
	printf("Thread %d is exiting.\n", thread_num);
	//The end of critical section.
	pthread_mutex_unlock(&mutex); //unlock mutex
	pthread_exit(NULL);
}
