/*************************************************************************
	> File Name: strstream.h
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Tue 14 Jul 2015 09:11:46 PM CST
    > Description: 
 ************************************************************************/

#ifndef __STRSTREAM_H__
#define __STRSTREAM_H__

typedef struct{
	char* begin;
	char* current;
}StrInputStream; /*String input stream*/
/*Init input stream*/
void initStrInutStream(StrInputStream*, char*);
/*Rewind the postion to the beginning*/
void sisRewind(StrInputStream*);
/*Check if it is the end of the input stream.*/
int sisEof(StrInputStream*);
/**/
int readInt(StrInputStream*, int*);
/**/
int readChar(StrInputStream*, char*);
/**/
int readDouble(StrInputStream*, double*);
/**/
int readString(StrInputStream*, char*);
#endif
