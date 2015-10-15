/*************************************************************************
	> File Name: stack.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 25 Sep 2015 11:06:13 AM CST
    > Description: 
 ************************************************************************/

#include <stdlib.h>
#include "stack.h"

int stackCreate(stack_t *stack, int stackSize)
{
	if((stackSize <= 0) || (stackSize > 1024))
		return -1;

	stack->storage = (int *)malloc(sizeof(int) * stackSize);

	if(stack->storage == NULL/* (void *)0 */)
		return -1;

	stack->state = STACK_CREATED;
	stack->max = stackSize;
	stack->index = 0;

	return 0;
}

int stackPush(stack_t *stack, int element)
{
	if((stack == (stack_t *)NULL) || (stack->state != STACK_CREATED) || (stack->index >= stack->max))
		return -1;

	stack->storage[stack->index] = element;
	stack->index++;

	return 0;
}

int stackPop(stack_t *stack, int *element)
{
	if((stack == NULL) || (stack->state != STACK_CREATED) || (stack->index <= 0))
		return -1;

	stack->index--;
	*element = stack->storage[stack->index];

	return 0;
}

int stackDestroy(stack_t *stack)
{
	if((stack == (stack_t *)NULL) || (stack->state != STACK_CREATED))
		return -1;

	stack->state = 0;
	free((void *)stack->storage);
	return 0;
}
