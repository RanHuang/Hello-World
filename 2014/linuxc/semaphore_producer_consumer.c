/*************************************************************************
	> File Name: semaphore_producer_consumer.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月25日 星期三 09时53分08秒
  > Description:4个线程，2 producer, 2 consumer, 生产者向buff随机写入capitical letter, consumer从buff读出data，直到读空buffer，若buff为null则block
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#include<string.h>

#define BUFFER_SIZE 5
#define A 65
#define Z 90

char share_buff[BUFFER_SIZE];
int idx_share_buff = -1;
int empty = 0;
int full = BUFFER_SIZE;

//synchronization
pthread_mutex_t mutex;
sem_t non_empty, non_full;
//
void *producer_func(void *arg)
{
	char ch;
	char *who;
	int position;
	
	who = (char*)arg;
	printf("Producer %s: Starting\n", who);

	while(1){
		srand((unsigned int)time(NULL));
		ch = (char)(rand()%(Z-A+1)+A);

		sem_wait(&non_full); //If some resource can be used
		pthread_mutex_lock(&mutex); //Mutex Lock

		position = ++idx_share_buff;
		share_buff[idx_share_buff] = ch;
		printf("Producer %s: Writing [%c] into buff[%d]\n", who, ch, position);

		sem_post(&non_empty);
		pthread_mutex_unlock(&mutex);//Mutex Unlock

		sleep(1);
	}
	return NULL;
}
//
void *consumer_func(void *arg)
{
	char ch;
	char *who;
	int position;
	
	who = (char*)arg;
	printf("Consumer %s: Starting\n", who);

	while(1){
		sem_wait(&non_empty); //If some resource can be used
		pthread_mutex_lock(&mutex); //Mutex Lock

		ch = share_buff[idx_share_buff];
		position = idx_share_buff--;
		printf("Consumer %s: Reading [%c] from buff[%d]\n", who, ch, position);

		sem_post(&non_full);
		pthread_mutex_unlock(&mutex);//Mutex Unlock

		sleep(1);
	}
	return NULL;
}
//
int main(int argc, char *argv[])
{
	pthread_t producer_one_thid, producer_two_thid, consumer_one_thid, consumer_two_thid;

	pthread_mutex_init(&mutex, NULL);
	/*
	 * Attention: full + empyt === BUFFER_SIZE
	 */
	sem_init(&non_empty, 0, empty);
	sem_init(&non_full, 0, full);

	
	pthread_create(&producer_one_thid, NULL, producer_func,"P1");
	pthread_create(&producer_two_thid, NULL, (void*)producer_func, "P2");
	pthread_create(&consumer_one_thid, NULL, consumer_func, "C1");
	pthread_create(&consumer_two_thid, NULL, (void*)consumer_func, "C2");

	pthread_join(producer_one_thid, NULL);
	pthread_join(producer_two_thid, NULL);
	pthread_join(consumer_one_thid, NULL);
	pthread_join(consumer_two_thid, NULL);

	sem_destroy(&non_full);
	sem_destroy(&non_empty);
	pthread_mutex_destroy(&mutex);

	return 0;
}
