/*************************************************************************
	> File Name: cat_fishing.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Mon 08 Jun 2015 08:20:36 PM CST
	> Description: 模拟小猫钓鱼游戏《啊哈！算法》pp40
 ************************************************************************/

#include<stdio.h>

#define QUEUESIZE 100
#define STACKSIZE 100
typedef struct queue{
	int data[QUEUESIZE];
	int front;
	int rear;
	int size;
	int capacity;
}Queue, *QueueP;

void createQueue(QueueP q, int max_elements)
{
	q->front = 0;
	q->rear = 0;
	if(max_elements < QUEUESIZE){
		q->capacity = max_elements;
	}else{
		q->capacity = QUEUESIZE;
	}
	q->size = 0;
}
int isQueueEmpty(QueueP q)
{
	return q->size == 0;
}
int isQueueFull(QueueP q)
{
	return q->size == q->capacity;
}
void makeQueueEmpty(QueueP q)
{
	q->front = 0;
	q->rear = 0;
	q->size = 0;
}
void enqueue(QueueP q, int element)
{
	/*
	if(isQueueFull(q)){
		printf("Queue is full!\n");
		exit(1);
	}*/
	q->data[q->rear] = element;
	q->rear++;
	if(q->rear == q->capacity) q->rear = 0;
	q->size++;
}
int frontOfQueue(QueueP q)
{
	return q->data[q->front];
}
void dequeue(QueueP q)
{
	int element;
	/*
	if(isQueueEmpty(q)){
		printf("Queue is empty!\n");
		exit(1);
	}
	*/
	q->front++;
	if(q->front == q->capacity) q->front = 0;
	q->size--;
}
typedef struct stack{
	int data[STACKSIZE];
	int top;
	int capacity;
}Stack, *StackP;

void createStack(StackP s, int stack_size)
{
	if(stack_size < STACKSIZE){
		s->capacity = stack_size;
	}else{
		s->capacity = STACKSIZE;
	}
	s->top = -1;
}
void makeStackEmpty(StackP s)
{
	s->capacity = 0;
	s->top = -1;
}
int isStackEmpty(StackP s)
{
	return s->top < 0;
}
int isStackFull(StackP s)
{
	return !(s->top < s->capacity-1);
}
void push(StackP s, int element)
{
	s->top++;
	s->data[s->top] = element;
}
int topOfStack(StackP s)
{
	return s->data[s->top];
}
void pop(StackP s){
	s->top--;
}

void stackTest();
void queueTest();
int main()
{
	queueTest();
	stackTest();
	return 0;
}
void stackTest()
{
	Stack sta;
	int i;
	createStack(&sta, 10);
	for(i=0; i<12 && !isStackFull(&sta); i++)
		push(&sta, i);
	printf("Stack(%d): ", i);
	while(!isStackEmpty(&sta)){
		printf("%d ", topOfStack(&sta));
		pop(&sta);
	}
	puts("\n");
}
void queueTest()
{
	Queue que;
	int i;
	createQueue(&que, 10);
	for(i=0; i<16 && !isQueueFull(&que); i++)
		enqueue(&que, 2*i);
	printf("Queue(%d): ", que.size);
	while(!isQueueEmpty(&que)){
		printf("%d ", frontOfQueue(&que));
		dequeue(&que);
	}
	printf("\n");
}
