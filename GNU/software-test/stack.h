/*************************************************************************
	> File Name: stack.h
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 25 Sep 2015 11:01:15 AM CST
    > Description: 
 ************************************************************************/

#ifndef __STACK_H__
#define __STACK_H__

#define STACK_CREATED 0xFAF32000
typedef struct{
	int state;
	int index;
	int max;
	int *storage;
} stack_t;

int stackCreate(stack_t *stack, int stackSize);

int stackPush(stack_t *stack, int element);

int stackPop(stack_t *stack, int *element);

int stackDestroy(stack_t *stack);

#endif
