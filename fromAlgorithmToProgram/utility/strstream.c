/*************************************************************************
	> File Name: strstream.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Tue 14 Jul 2015 09:29:38 PM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include"strstream.h"

void initStrInutStream(StrInputStream* sis, char* s)
{
	/*输入流中数据项之间用空格作为分隔符*/
	while(*s == ' ' || *s == '\t')
		s++;
	sis->begin = sis->current = s;
}
/*Rewind the postion to the beginning*/
void sisRewind(StrInputStream* sis)
{
	sis->current = sis->begin;
}
/*Check if it is the end of the input stream.*/
int sisEof(StrInputStream* sis)
{
	return ( (strlen(sis->current)==0) || (*(sis->current) == '\r') || (*(sis->current) == '\n') );
}
