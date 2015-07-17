/*************************************************************************
	> File Name: searchengine.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Wed 15 Jul 2015 03:14:37 PM CST
    > Description: 
		SEARCH-ENGINE(fin, fout)
		  open fin, fout
		  while not end of fin
			do firt-str <- read a line from fin
			  type <- the first character of first-str
			  key <- 根据type类型从first-str中提取关键字
			  second-str <- read a line from fin
			  i <- SEARCH(key, second-str)
			  if i>0
			    then write i to fout
				else write "not found!" to fout
		   close fin, fout

		SEARCH(key, second-str)
		  n <- 0
		  while data in second-str
			do x <- get a data from second-str
			  n++
			  A[n] = x
		  return LINEAR-SEARCH(A, sizeof(type), n, key, cmpFunction)
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include"compare.h"
#include"search.h"
#include"strstream.h"

int main(int argc, char* argv[])
{
	char first[80];
	FILE *fin, *fout;
	int i, j, n;
	char type, second[254];

	int key_int, arr_int[63];
	double key_double, arr_double[31];
	char key_char, arr_char[254];
	char *key_str, *arr_str[80];
	
	fin = fopen("input.txt", "r");
	if(fin == NULL){
		int err = errno;
		printf("errno:%d\n", errno);
		errno = err;
		perror("Open file input.txt");
		exit(1);
	}
	fout = fopen("output.txt", "w");
	if(fout == NULL){
		fprintf(stderr, "%s, line %d: %s\n",
					__FILE__, __LINE__, strerror(errno));
		exit(1);
	}
	/*
	 * assert(fin&&fout);
	 */
	fgets(first, 80, fin);
	while(!feof(fin)){
		i = -1;
		StrInputStream sin;
		initStrInputStream(&sin, first);
		readChar(&sin, &type);
		n = 0;
		switch(type){
			case 'i':
				readInt(&sin, &key_int);
				fgets(second, 254, fin);
				initStrInputStream(&sin, second);
				while(!sisEof(&sin))
					readInt(&sin, &arr_int[n++]);
				i = linearSearch(arr_int, sizeof(int), n, &key_int, intComp);
				/*Debug*/
				printf("key: %d, n= %d\n", key_int, n);
				for(j=0; j<n; j++){
					printf("%d ", arr_int[j]);
				}
				break;
			case 'f':
				readDouble(&sin, &key_double);
				fgets(second, 254, fin);
				initStrInputStream(&sin, second);
				while(!sisEof(&sin))
					readDouble(&sin, &arr_double[n++]);
				i = linearSearch(arr_double, sizeof(double), n, &key_double, doubleComp);
				/*Debug*/
				printf("key: %f, n= %d\n", key_double, n);
				for(j=0; j<n; j++){
					printf("%f ", arr_double[j]);
				}
				break;
			case 'c':
				readChar(&sin, &key_char);
				fgets(second, 254, fin);
				initStrInputStream(&sin, second);
				while(!sisEof(&sin))
					readChar(&sin, &arr_char[n++]);
				i = linearSearch(arr_char, sizeof(char), n, &key_char, charComp);
				/*Debug*/
				printf("key: %c, n= %d\n", key_char, n);
				for(j=0; j<n; j++){
					printf("%c ", arr_char[j]);
				}
				break;
			case 's':
				key_str = (char*)malloc(256*sizeof(char));
				for(j = 0; j < 80; j++)
					arr_str[j] = (char*)malloc(256*sizeof(char));
				readString(&sin, key_str);
				fgets(second, 254, fin);
				initStrInputStream(&sin, second);
				while(!sisEof(&sin)){
					if(!readString(&sin, arr_str[n]))
						break;
					n++;
				}
/*
				i = linearSearch(arr_str, sizeof(char*), n, key_str, strcmp);
				* strcmp can not work well in the linearSearch.
				*/
				i = 0;
				while(i < n){
					if(strcmp(key_str, arr_str[i]) == 0)
						break;
					i++;
				}
				if(i>=n) i = -1;

				/*Debug*/
				printf("\nkey: %s, n= %d\n", key_str, n);
				for(j=0; j<n; j++){
					printf("%s %s %d\n", key_str, arr_str[j], strcmp(key_str, arr_str[j]));
				}

				free(key_str);
				for(j=0; j<80; j++)
					free(arr_str[j]);
				break;
			default:
				fprintf(stderr, "Unknown type!\n");
				exit(1);
		} 
		/* do{}while(); does not work well.
		 * It seems that even the last line has been read, there is still
		 * some charater in the file. The feof(fin) is not true.
		 */
		/*Debug*/
		printf("\n  %d  \n\n", i+1);

		if(i > -1)
			fprintf(fout, "%d\n", i+1);
		else
			fprintf(fout, "not found!\n");

		fgets(first, 80, fin);
	}	
	fclose(fin);
	fclose(fout);
	return EXIT_SUCCESS;
}
