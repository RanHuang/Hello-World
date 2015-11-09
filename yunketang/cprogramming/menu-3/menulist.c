/*************************************************************************
	> File Name: menulist.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Mon 02 Nov 2015 09:38:48 AM CST
    > Description: 
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include "linkedlist.h"
#include "menulist.h"

tCmdNode* FindCmd(tLinkedList *pList, const char* str_cmd)
{
	tCmdNode *p;
	p = (tCmdNode *)GetLinkedListHead(pList);

	assert(str_cmd != NULL);

	while(p != NULL){
		if(strcmp(p->cmd, str_cmd) == 0){
			return p;
		}else{
			p = (tCmdNode *)GetNextLinkedListNode(pList, (tLinkedListNode *)p);
		}
	}

	printf("Unknown CMD: %s\n", str_cmd);

	return NULL;	
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
