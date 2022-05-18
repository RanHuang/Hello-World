/*************************************************************************
	> File Name: menu.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 19 Sep 2015 04:03:07 PM CST
    > Description: 
		代码风格规范：简明、易读、无二义性
 ************************************************************************/

/**
 *  Version 1.0
 *	Revision Log:
 *
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu_print();

int main()
{
    char cmd[128];

    while(1){
        printf(">>");
        scanf("%s", cmd);
        if(strcmp(cmd, "quit") == 0){
            exit(0);
        }else if(strcmp(cmd, "help") == 0){
            menu_print();
        }else if(strcmp(cmd, "version") == 0){
            printf("print the version of this program.\n");
        }else{
            printf("Unknown command.\n");
        }
    }
    return 0;
}

void menu_print()
{
    printf("The instructions of commands about this program.\n"
           "  help    , Usage about this program\n"
           "  quit    , Terminate the program\n"
           "  version , Version of this program\n"
           "  Example: >>help\n");
}
