/*************************************************************************
	> File Name: menulist.h
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Mon 02 Nov 2015 09:33:13 AM CST
    > Description: 
 ************************************************************************/

typedef struct CmdNode{
	char* cmd;
	char* cmd_desc;
	int (*handler)();
	struct CmdNode *next;
}tCmdNode, *tCmdList;

tCmdNode* FindCmd(tCmdNode *head, const char* str_cmd);

void ShowCmdInfo(tCmdList list);
