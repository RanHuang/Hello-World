/*************************************************************************
	> File Name: menulist.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Mon 02 Nov 2015 09:38:48 AM CST
    > Description: 
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "linkedlist.h"
#include "menulist.h"

tCmdNode* FindCmd(tLinkedList *pList, const char* str_cmd)
{
	tCmdNode *p = NULL;

	p = (tCmdNode *)SearchLinkedListNode(pList, SearchCmdCondition, (void *)str_cmd);

	if(p == NULL){
		printf("Unknown CMD: %s\n", str_cmd);
	}

	return p;
}

void ShowHelpInfo(tLinkedList *cmd_list)
{
	tCmdNode *p;
	p = (tCmdNode *)GetLinkedListHead(cmd_list);

	printf("The instructions about commands of this program.\n");
	while(p != NULL){
		printf("  %-10s, %s\n", p->cmd, p->cmd_desc);	

		p = (tCmdNode *)GetNextLinkedListNode(cmd_list, (tLinkedListNode *)p);
	}
	printf("  Example: >>help\n");
}

int SearchCmdCondition(tLinkedListNode *pListNode, void *arg)
{
	tCmdNode *pNode = NULL;
	char *str_cmd = (char *)arg;

	pNode = (tCmdNode *)pListNode;
	if(strcmp(pNode->cmd, str_cmd) == 0){
		return SUCCESS;
	}

	return FAILURE;
}
