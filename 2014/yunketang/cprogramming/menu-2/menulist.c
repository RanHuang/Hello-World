/*************************************************************************
	> File Name: menulist.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Mon 02 Nov 2015 09:38:48 AM CST
    > Description: 
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include "menulist.h"

tCmdNode* FindCmd(tCmdNode* head, const char* str_cmd)
{
	tCmdNode *p;
	p = head;

	assert(str_cmd != NULL);

	while(p != NULL){
		if(strcmp(p->cmd, str_cmd) == 0){
			return p;
		}else{
			p = p->next;
		}
	}

	printf("Unknown CMD: %s\n", str_cmd);

	return NULL;	
}

void ShowHelpInfo(tCmdList cmd_list)
{
	tCmdNode *p;
	p = cmd_list;

	printf("The instructions about commands of this program.\n");
	while(p != NULL){
		printf("  %-10s, %s\n", p->cmd, p->cmd_desc);	
		p = p->next;
	}
	printf("  Example: >>help\n");
}
