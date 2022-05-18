/*************************************************************************
	> File Name: menulist.h
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Mon 02 Nov 2015 09:33:13 AM CST
    > Description: 
 ************************************************************************/
#ifndef _MENU_LIST_H_
#define _MENU_LIST_H_

#include "linkedlist.h"

typedef struct CmdNode{
	tLinkedListNode *pNext;
	char* cmd;
	char* cmd_desc;
	int (*handler)();
}tCmdNode;

tCmdNode* FindCmd(tLinkedList *pList, const char* str_cmd);

int SearchCmdCondition(tLinkedListNode *pListNode, void *arg);

void ShowCmdInfo(tLinkedList *pList);

#endif
