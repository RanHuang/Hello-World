/*************************************************************************
	> File Name: test.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Tue 10 Nov 2015 08:06:19 PM CST
    > Description: 
 ************************************************************************/

#include <stdio.h>
#include "menu.h"

int main(int argc, char *argv[])
{
	MenuConfig("version", "Show the version of the Menu Program", ShowVersion);
	MenuConfig("quit", "Exit from the Menu Program", Quit);

	ExecuteMenu();

	return 0;
}


