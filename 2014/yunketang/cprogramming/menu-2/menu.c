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

#define MAX_LEN_CMD 128

int Help();
int ShowVersion();
int Quit();

static char *Version = "V 0.1";

static tCmdNode head[] = {
	{"help", "Usage about this program", Help, &head[1]},
	{"version", "Show the version of this program", ShowVersion, &head[2]},
	{"quit", "Quit this program", Quit, NULL}
};

int main()
{
    char cmd[MAX_LEN_CMD];
	tCmdNode *p_cmd;

    while(1){
        printf("Input a command: >>");
        scanf("%s", cmd);

		p_cmd = FindCmd(head, cmd);

		if(p_cmd != NULL && p_cmd->handler != NULL){
			p_cmd->handler();
		}
    }

    return 0;
}

int Help()
{
	ShowHelpInfo(head);
	return 0;
}
int ShowVersion()
{
	printf("menu : %s\n", Version);
	return 0;
}
int Quit()
{
	printf("Exit form this program.\n");
	exit(0);
}
