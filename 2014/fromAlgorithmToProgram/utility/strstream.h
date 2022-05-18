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
void initStrInputStream(StrInputStream*, char*);
/*Rewind the postion to the beginning*/
void sisRewind(StrInputStream*);
/*Check if it is the end of the input stream.*/
int sisEof(StrInputStream*);
/**/
int readChar(StrInputStream*, char*);
/**/
int readInt(StrInputStream*, int*);
/**/
int readDouble(StrInputStream*, double*);
/**/
int readString(StrInputStream*, char*);

typedef struct{
	char* begin;
	char* current;
	int length;
}StrOutputStream;
/*The global string output stream*/
StrOutputStream gsos;
/**/
void initStrOutputStream(StrOutputStream*, int);
/**/
void freeStrOutputStream(StrOutputStream*);
/**/
void sosRewind(StrOutputStream*);
/**/
int sosFull(StrOutputStream*);
/**/
int writeChar(StrOutputStream*, char);
/**/
int writeInt(StrOutputStream*, int);
/**/
int writeDouble(StrOutputStream*, double);
/**/
int writeString(StrOutputStream*, char*);

/**/
void putChar(char*);
void putInt(int*);
void putDouble(double*);
void putString(char*);
 
#endif
