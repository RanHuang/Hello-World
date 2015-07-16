/*************************************************************************
	> File Name: strstream.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Tue 14 Jul 2015 09:29:38 PM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"strstream.h"

void initStrInputStream(StrInputStream* sis, char* s)
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

void skipBlankSpace(StrInputStream* sis)
{
	while(*(sis->current)==' ' || *(sis->current)=='\t')
		(sis->current) ++;
}

int readChar(StrInputStream* sis, char* x)
{
	char str[80];
	int slen;
	
	skipBlankSpace(sis);

	sscanf(sis->current, "%s", str); /*Read data from current position.*/
	slen = strlen(str);

	if(slen == 0) /*There is no data.*/
		return 0;
	sis->current += slen;
	*x = str[0]; /*Change string to char.*/
	return 1;
}

int readInt(StrInputStream* sis, int* x)
{
	char str[80];
	int slen;

	while(*(sis->current)==' ' || *(sis->current)=='\t')
		(sis->current) ++;    /*Skip the blank space*/

	sscanf(sis->current, "%s", str); /*Read data from current position.*/
	slen = strlen(str);

	if(slen == 0) /*There is no data.*/
		return 0;
	sis->current += slen;
	*x = atoi(str); /*Change string to integer.*/
	return 1;
}

int readDouble(StrInputStream* sis, double* x)
{
	char str[80];
	int slen;

	skipBlankSpace(sis);

	sscanf(sis->current, "%s", str); /*Read data from current position.*/
	slen = strlen(str);

	if(slen == 0) /*There is no data.*/
		return 0;
	sis->current += slen;
	*x = atof(str); /*Change string to float.*/
	return 1;
}

int readString(StrInputStream* sis, char* x)
{
	int slen;
	
	skipBlankSpace(sis);

	sscanf(sis->current, "%s", x); /*Read data from current position.*/
	slen = strlen(x);

	if(slen == 0) /*There is no data.*/
		return 0;
	sis->current += slen;
	return 1;
}
/**
 *
 */
void initStrOutputStream(StrOutputStream* sos, int size)
{
	/*Allocate space for output buffer.*/
	if(sos->begin = (char*)malloc(size*sizeof(char))){
		sos->length = size;
		memset(sos->begin, 0, size*sizeof(char));
		sos->current = sos->begin;
	}
}
/**/
void freeStrOutputStream(StrOutputStream* sos)
{
	sos->length = 0;
	sos->current = NULL;
	if(sos->begin)
		free(sos->begin);
}
/**/
void sosRewind(StrOutputStream* sos)
{
	sos->current = sos->begin;
}
/**/
int sosFull(StrOutputStream* sos)
{
	return sos->current - sos->begin >= sos->length;/*sos->length <= size*/
}
/**/
int writeChar(StrOutputStream* sos, char c)
{
	if(sosFull(sos))
		return 0;
	if(sos->current == sos->begin)
		sprintf(sos->current, "%c", c);
	else
		sprintf(sos->current, " %c", c);
	sos->current += strlen(sos->current);
	return 1;
}
/**/
int writeInt(StrOutputStream* sos, int x)
{
	if(sosFull(sos))
		return 0;
	if(sos->current == sos->begin)
		sprintf(sos->current, "%d", x);
	else
		sprintf(sos->current, " %d", x);
	sos->current += strlen(sos->current);
	return 1;
}
/**/
int writeDouble(StrOutputStream* sos, double x)
{
	if(sosFull(sos))
		return 0;
	if(sos->current == sos->begin)
		sprintf(sos->current, "%f", x);
	else
		sprintf(sos->current, " %f", x);
	sos->current += strlen(sos->current);
	return 1;
}
/**/
int writeString(StrOutputStream* sos, char* s)
{
	if(sosFull(sos))
		return 0;
	if(sos->current == sos->begin)
		sprintf(sos->current, "%s", s);
	else
		sprintf(sos->current, " %s", s);
	sos->current += strlen(sos->current);
	return 1;
}

/**/
void putChar(char* c)
{
	writeChar(&gsos, *c);
}
void putInt(int* x)
{
	writeInt(&gsos, *x);
}
void putDouble(double* x)
{
	writeDouble(&gsos, *x);
}
void putString(char* s)
{
	writeString(&gsos, s);
}
