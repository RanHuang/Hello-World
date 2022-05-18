/*************************************************************************
	> File Name: cond_producer_consumer.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月24日 星期二 20时45分55秒
  > Description: 使用互斥锁与条件变量演示一个生产者与消费者的例子
  生产者不断向缓冲区写入大写字母；消费者不断从缓冲区获得字母；缓冲区最多方5个字母，生产者写满缓冲区则消费者才能开始读，缓冲区空则生产者才能开始写；直到缓冲区写入'Z'程序结束。
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define PRODUCT_MAX 5
//structure of the product
typedef struct{
	char buff[PRODUCT_MAX]; //
	int num;           //Store num capital letters
}PRODUCT;
PRODUCT products = {"",0};
char ch = 'A';
#define END_CHAR 'Z'
//synchronization
pthread_mutex_t mutex;
pthread_cond_t cond;
//
void *producer_func(void *arg)
{
	pthread_t producer_thid;
	producer_thid = pthread_self();
	printf("Producer %lu: Starting\n", producer_thid);

	while(END_CHAR > ch){
		pthread_mutex_lock(&mutex); //Mutex Lock
		if(products.num != PRODUCT_MAX){
			products.buff[products.num] = ch;
			printf("Producer %lu: Putting[%c] into buffer.\n", producer_thid, ch);
			products.num++;
			ch++;
			//If condition is met, signal.
			if(PRODUCT_MAX == products.num){
				printf("Producter %lu: Buffer is full!!!!\n", producer_thid);
				pthread_cond_signal(&cond);
			}
		}
		pthread_mutex_unlock(&mutex); //Mutex Unlock

		sleep(1);
	}
	printf("Producer %lu: Exiting\n", producer_thid);
	return NULL;
}
//
void *consumer_func(void *arg)
{
	pthread_t consumer_thid;
	int i;
	consumer_thid = pthread_self();
	printf("Consumer %lu: Starting\n", consumer_thid);
	while(END_CHAR > ch){
		pthread_mutex_lock(&mutex); //Mutex Lock
		//?? one mutex, but used twice ??
		printf("Consumer %lu: Waiting...\n", consumer_thid);
		//if also OK
		while(products.num != PRODUCT_MAX){
			pthread_cond_wait(&cond, &mutex);
		}
		printf("Consumer %lu: Getting letters from buffer.\n", consumer_thid);
		for(i=0; products.buff[i]&&products.num; i++, products.num--){
			putchar(products.buff[i]);
		}
		printf("\n");
		pthread_mutex_unlock(&mutex);
	}
	printf("Consumer %lu: EXiting....\n", consumer_thid);
	return NULL;
}
//
int main(int argc, char *argv[])
{
	pthread_t producer_thid, consumer_thid;
	void *retval;

	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
	
	pthread_create(&producer_thid, NULL, (void*)producer_func, NULL);
	pthread_create(&consumer_thid, NULL, (void*)consumer_func, NULL);

	pthread_join(producer_thid, &retval);
	pthread_join(consumer_thid, &retval);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;
}
