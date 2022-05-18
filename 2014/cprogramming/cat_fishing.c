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
void initialize(QueueP a, QueueP b, StackP c);

int main()
{
	Queue Alice, Bob;
	Stack desk;
	int board;
	int book[16]={0};
	int count = 0; //出牌计数，避免出现死循环
	initialize(&Alice, &Bob, &desk);
	while(!(isQueueEmpty(&Alice) || isQueueEmpty(&Bob)) && count<10000){
		count++;
		//Alice 出牌
		board = frontOfQueue(&Alice);
		dequeue(&Alice);
		if(book[board] == 0){
			push(&desk, board);
			book[board] = 1;
		}else{
			enqueue(&Alice, board);
			while(topOfStack(&desk) != board){
				book[topOfStack(&desk)] = 0;
				enqueue(&Alice, topOfStack(&desk));
				pop(&desk);
			}
			book[topOfStack(&desk)] = 0;
			enqueue(&Alice, topOfStack(&desk));
			pop(&desk);
		}
		if(isQueueEmpty(&Alice)) break; //Alice has no board, she wins.
		//Bob 出牌
		board = frontOfQueue(&Bob);
		dequeue(&Bob);
		if(book[board] == 0){
			push(&desk, board);
			book[board] = 1;
		}else{
			enqueue(&Bob, board);
			while(topOfStack(&desk) != board){
				book[topOfStack(&desk)] = 0;
				enqueue(&Bob, topOfStack(&desk));
				pop(&desk);
			}
			book[topOfStack(&desk)] = 0;
			enqueue(&Bob, topOfStack(&desk));
			pop(&desk);
		}
		if(isQueueEmpty(&Bob)) break; //Bob has no board, he wins.
	}
	//Result
	if(isQueueEmpty(&Alice)){
		puts("\tAlice wins!");
	}else if(isQueueEmpty(&Bob)){
		puts("\t Bob wins!");
	}else{
		printf("After %d round, nobody wins.\n", count);
	}
	
	//Print
	printf("Alice: ");
	while(!isQueueEmpty(&Alice)){
		printf("%d ", frontOfQueue(&Alice));
		dequeue(&Alice);
	}
	printf("\nBob: ");
	while(!isQueueEmpty(&Bob)){
		printf("%d ", frontOfQueue(&Bob));
		dequeue(&Bob);
	}
	printf("\nThe Desktop(Reverse order): ");
	
	while(!isStackEmpty(&desk)){
		printf("%d ", topOfStack(&desk));
		pop(&desk);
	}
	puts("\n");

	return 0;
}

void initialize(QueueP a, QueueP b, StackP c)
{
	int x[10] = {2, 4, 1, 2, 5 ,6};
	int y[10] = {3, 1, 3, 5, 6, 4};
	int i;
	createQueue(a, 20);
	createQueue(b, 20);
	createStack(c, 20);
	for(i=0; i<QUEUESIZE && i<6; i++){
		enqueue(a, x[i]);
		enqueue(b, y[i]);
	}
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
