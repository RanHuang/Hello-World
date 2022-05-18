/*************************************************************************
	> File Name: testlinkedlist.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Mon 09 Nov 2015 09:10:28 AM CST
    > Description: 
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "linkedlist.h"

#define debug

typedef struct Node{
	tLinkedListNode *pNext;
	int data;
}tNode;

tNode *Search(tLinkedList *pLinkedList);

int main()
{
	int i;
	tNode *pNode = NULL;
	tLinkedList *pList = NULL;
	
	pList = CreateLinkedList();
	if(pList == NULL){
		printf("Error: CreateLinkedList\n");
		exit(0);
	}

	for(i=0; i<10; i++){
		pNode = (tNode*)malloc(sizeof(tNode));
		pNode->data = i;
		debug("add linkedlist node\n");
		printf("Add pNode->data = %d\n", pNode->data);
		AddLinkedListNode(pList, (tLinkedListNode *)pNode);
	}

	pNode = NULL;
	pNode = Search(pList);
	printf("Search Node: data = %d\n", pNode->data);

	debug("Delete node from the linked list.\n");
	DeleteLinkedListNode(pList, (tLinkedListNode*)pNode);
	free(pNode);

	debug("Delete Linked List\n");
	DeleteLinkedList(pList);
	pList = NULL;

	Search(pList);

	return SUCCESS;
}

#define SEARCH_DATA 5

tNode *Search(tLinkedList *pLinkedList)
{
	tNode *pNode = NULL;

	pNode = (tNode *)GetLinkedListHead(pLinkedList);
	debug("search linked list\n");
	while(pNode != NULL){
		if(pNode->data == (SEARCH_DATA))
		{
			printf("Find the node: data = %d\n", (SEARCH_DATA));
			return pNode;
		}
		pNode = (tNode *)GetNextLinkedListNode(pLinkedList, (tLinkedListNode *)pNode);
	}

	printf("Can not find the node with data %d\n", (SEARCH_DATA));
	return NULL;
}
