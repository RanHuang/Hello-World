/*************************************************************************
	> File Name: menu.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 19 Sep 2015 04:03:07 PM CST
    > Description: 
		代码风格规范：简明、易读、无二义性
 ************************************************************************/

/**
 *  Version 2.0
 *	Revision Log:
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menulist.h"
#include "linkedlist.h"
#include "menu.h"

void DeleteMenu(tLinkedList *pList);

static char *Version = "V 0.1";

tLinkedList *pList = NULL;

int ExecuteMenu()
{
    char cmd[MAX_LEN_CMD];
	tCmdNode *p_cmd;

    while(1){
        printf("Input a command: >>");
        scanf("%s", cmd);

		p_cmd = FindCmd(pList, cmd);

		if(p_cmd != NULL && p_cmd->handler != NULL){
			p_cmd->handler();
		}
    }

    return 0;
}

int MenuConfig(char *cmd, char *desc, int (*handler)())
{
	tCmdNode *pNode = NULL;

	if(pList == NULL){
		pList = CreateLinkedList();
	
		pNode = (tCmdNode *)malloc(sizeof(tCmdNode));
		pNode->cmd = "help";
		pNode->cmd_desc = "Usage about this program";
		pNode->handler = Help;
		AddLinkedListNode(pList, (tLinkedListNode *)pNode);
	}
	pNode = (tCmdNode *)malloc(sizeof(tCmdNode));
	pNode->cmd = cmd;
	pNode->cmd_desc = desc;
	pNode->handler = handler;
	AddLinkedListNode(pList, (tLinkedListNode *)pNode);

	return 0;
}

int Help()
{
	ShowHelpInfo(pList);
	return 0;
}
int ShowVersion()
{
	printf("menu : %s\n", Version);
	return 0;
}
int Quit()
{
	DeleteMenu(pList);

	printf("Exit form this program.\n");
	exit(0);
}

void DeleteMenu(tLinkedList *pList)
{
	DeleteLinkedList(pList);

	return;
}
