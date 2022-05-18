/*************************************************************************
	> File Name: menu.h
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Tue 10 Nov 2015 07:38:37 PM CST
    > Description: 
 ************************************************************************/
#ifndef _MENU_H_
#define _MENU_H_

#define MAX_LEN_CMD 128

/* add cmd to menu */
int MenuConfig(char *cmd, char *desc, int (*handler)());

/* Menu Engine Execute */
int ExecuteMenu();

int Help();
int ShowVersion();
int Quit();

#endif
