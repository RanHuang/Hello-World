/*************************************************************************
	> File Name: search.h
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sun 05 Jul 2015 10:37:51 AM CST
    > Description: 
 ************************************************************************/
#ifndef __SEARCH_H__
#define __SEARCH_H__

/* 线性搜索 */
int linearSearch(void *a, int size, int n, void *x, int(*comp)(void*, void*));
/* Binary Search */
int binSearch(void *a, int size, int n, void *x, int(*comp)(void*, void*));

#endif /* __SEARCH_H__ */
