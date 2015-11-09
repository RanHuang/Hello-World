/*************************************************************************
	> File Name: linkedlist.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 07 Nov 2015 06:19:32 PM CST
    > Description: 
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

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

	return pLinkedList;
}

int DeleteLinkedList(tLinkedList *pLinkedList)
{
	tLinkedListNode *pNode = NULL;
	tLinkedListNode *pTempNode = NULL;

	if(pLinkedList == NULL){
		printf("Linked List should not be NULL!\n");
		return FAILURE;
	}
	
	pNode = pLinkedList->pHead;

	while(pNode != NULL){
		pTempNode = pNode->pNext;
		free(pNode);
		pNode = pTempNode;
	}
	
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

	if(pLinkedList->numOfNode == 0){
		pLinkedList->pHead = pNode;
		pLinkedList->pTail = pNode;
	}else{
		pLinkedList->pTail->pNext = pNode;
		pLinkedList->pTail = pNode;
	}
	pNode->pNext = NULL;
	pLinkedList->numOfNode++;

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
		
		return SUCCESS;
	}else{
		printf("No matched node in the list.\n");
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
