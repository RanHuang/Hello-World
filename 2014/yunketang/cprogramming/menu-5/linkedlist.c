/*************************************************************************
	> File Name: linkedlist.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 07 Nov 2015 06:19:32 PM CST
    > Description: 
	> Modify: 线程安全的通用链表--互斥锁
		可能存在问题，使用读写锁使其绝对线程安全
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "linkedlist.h"

/**
 * 隐藏链表结构信息
 * Linked List
 */
struct LinkedList{
	tLinkedListNode *pHead;
	tLinkedListNode *pTail;
	int numOfNode;
	pthread_mutex_t mutex;
};

tLinkedList *CreateLinkedList()
{
	tLinkedList *pLinkedList = NULL;

	pLinkedList = (tLinkedList *)malloc(sizeof(tLinkedList));
	if(pLinkedList == NULL){
		return NULL;
	}

	pLinkedList->pHead = NULL;
	pLinkedList->pTail = NULL;
	pLinkedList->numOfNode = 0;
	pthread_mutex_init(&(pLinkedList->mutex), NULL);

	return pLinkedList;
}

int DeleteLinkedList(tLinkedList *pLinkedList)
{
	tLinkedListNode *pNode = NULL;

	if(pLinkedList == NULL){
		printf("Linked List should not be NULL!\n");
		return FAILURE;
	}
	
	while(pLinkedList->pHead != NULL){
		pNode = pLinkedList->pHead;

		pthread_mutex_lock(&(pLinkedList->mutex));
		pLinkedList->pHead = pLinkedList->pHead->pNext;
		pLinkedList->numOfNode--;
		pthread_mutex_unlock(&(pLinkedList->mutex));

		free(pNode);
	}
	
	pthread_mutex_destroy(&(pLinkedList->mutex));
	/**
	 * 如果同时删除同一个链表可能存在问题
	 */
	free(pLinkedList);

	return SUCCESS;
}
/**
 * Add the node at the tail.
 */
int AddLinkedListNode(tLinkedList *pLinkedList, tLinkedListNode *pNode)
{
	if(pLinkedList == NULL || pNode == NULL){
		printf("List or Node should not be NULL!\n");
		return FAILURE;
	}

	pthread_mutex_lock(&(pLinkedList->mutex));

	if(pLinkedList->numOfNode == 0){
		pLinkedList->pHead = pNode;
		pLinkedList->pTail = pNode;
	}else{
		pLinkedList->pTail->pNext = pNode;
		pLinkedList->pTail = pNode;
	}
	pNode->pNext = NULL;
	pLinkedList->numOfNode++;

	pthread_mutex_unlock(&(pLinkedList->mutex));

	return SUCCESS;
}
/**
 * The delete operation will be easier, if the node was added at the head.
 */
int DeleteLinkedListNode(tLinkedList *pList, tLinkedListNode *pNode)
{
	tLinkedListNode *pListNode = NULL;
	tLinkedListNode *qListNode = NULL;

	if(pList == NULL || pNode == NULL){
		printf("List or Node should not be NULL!\n");
		return FAILURE;
	}

	pthread_mutex_lock(&(pList->mutex));

	pListNode = pList->pHead;
	while(pListNode != NULL && pListNode != pNode){
		qListNode = pListNode;
		pListNode = pListNode->pNext;
	}
	
	if(pListNode == pNode){
		if(pListNode == pList->pHead){
			pList->pHead = pListNode->pNext;
		}else if(pListNode == pList->pTail){
			pList->pTail = qListNode;
			qListNode->pNext = pListNode->pNext;
		}else{
			qListNode->pNext = pListNode->pNext;
		}
		//free(pListNode);
		pList->numOfNode--;
		
		pthread_mutex_unlock(&(pList->mutex));

		return SUCCESS;
	}else{
		printf("No matched node in the list.\n");

		pthread_mutex_unlock(&(pList->mutex));

		return FAILURE;
	}	
}

tLinkedListNode *GetLinkedListHead(tLinkedList *pLinkedList)
{
	if(pLinkedList != NULL){
		return pLinkedList->pHead;
	}
	return NULL;
}

tLinkedListNode *GetNextLinkedListNode(tLinkedList *pList, tLinkedListNode *pNode)
{
	tLinkedListNode *pListNode;

	if(pList == NULL || pNode == NULL){
		printf("List or Node should not be NULL!\n");
		return NULL;
	}

	pListNode = pList->pHead;
	while(pListNode != NULL){
		if(pListNode == pNode){
			return pListNode->pNext;
		}
		pListNode = pListNode->pNext;
	}
	return NULL;
}
tLinkedListNode *SearchLinkedListNode(tLinkedList *pList, int Condition(tLinkedListNode *pNode, void *arg), void *arg)
{
	tLinkedListNode *pListNode;

	if(pList == NULL){
		printf("List should not be NULL!\n");
		return NULL;
	}

	pListNode = pList->pHead;

	while(pListNode != NULL){
		if(Condition(pListNode, arg) == SUCCESS){
			return pListNode;
		}
		pListNode = pListNode->pNext;
	}

	return NULL;
}
