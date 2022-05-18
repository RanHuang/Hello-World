/*************************************************************************
	> File Name: link_list.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 19 Jun 2015 09:43:25 PM CST
	> Description:简单链表的创建、数据插入练习,由小到大创建整数链表
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct node{
		int data;
		struct node *next;
	};

	struct node *head, *p, *q;
	int i, n;
	int data;
	head = p = q = NULL;
	printf("The number of intergers to insert(n):");
	scanf("%d", &n);
	if(n < 1){
		puts("n should at least be 1.");
		exit(1);
	}
	head = (struct node *)malloc(sizeof(struct node)); //设头指针
	head->next = NULL;
	for(i=0; i<n; i++){
		printf("Input the %dth integer:", i+1);
		scanf("%d", &data);
		//Create a node
		p = (struct node *)malloc(sizeof(struct node));
		p->data = data;
		p->next = NULL;
		//Find the proper position to place the node, from small to big  
		q = head;
		while(q != NULL){
			if((q->next == NULL) || (q->next->data > p->data)){
				p->next = q->next;
				q->next = p;
				break;
			}
			q = q->next;
		}
	}
	//Print the whole link list
	p = head->next;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	//Free the space
	q = head;
	while(q != NULL){
		p = q;
		q = q->next;
		free(p);
	}
	head = NULL;
	
	return 0;
}
