/*************************************************************************
	> File Name: linkedlist.h
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 07 Nov 2015 06:19:20 PM CST
    > Description: 
 ************************************************************************/

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

//#include <pthread.h>

#define SUCCESS 0
#define FAILURE (-1)
/**
 * Linked List Node
 */
typedef struct LinkedListNode{
	struct LinkedListNode *pNext;
}tLinkedListNode;
/**
 * Linked List
 */
typedef struct LinkedList{
	tLinkedListNode *pHead;
	tLinkedListNode *pTail;
	int numOfNode;
//	pthread_mutext_mutex;
}tLinkedList;
/**
 *
 */
tLinkedList *CreateLinkedList();

int DeleteLinkedList(tLinkedList *pLinkedList);

int AddLinkedListNode(tLinkedList *pLinkedList, tLinkedListNode *pNode);

int DeleteLinkedListNode(tLinkedList *pLinkedList, tLinkedListNode *pNode);

tLinkedListNode *GetLinkedListHead(tLinkedList *pLinkedList);

tLinkedListNode *GetNextLinkedListNode(tLinkedList *pLinkedList, tLinkedListNode *pNode);
#endif
