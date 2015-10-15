/*************************************************************************
	> File Name: cut_test.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Thu 15 Oct 2015 03:59:28 PM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include"stack.h"
#include"cut.h"

stack_t myStack_1;
stack_t myStack_2;

void __CUT_BRINGUP__Explode(void)
{
	int ret;
	printf("Stack test bringup called\n");

	ret = stackCreate(&myStack_1, 5);
	ASSERT((ret == 0), "Stack 1 creation.");

	ret = stackCreate(&myStack_2, 5);
	ASSERT((ret == 0), "Stack 2 creation.");
}

void __CUT__PushConsumptionTest(void)
{
	int ret;
	/* Exhaust the stack. */

	ret = stackPush(&myStack_1, 1);
	ASSERT((ret == 0), "Stack push 1 failed.");

	ret = stackPush(&myStack_1, 2);
	ASSERT((ret == 0), "Stack push 2 failed.");

	ret = stackPush(&myStack_1, 3);
	ASSERT((ret == 0), "Stack push 3 failed.");

	ret = stackPush(&myStack_1, 4);
	ASSERT((ret == 0), "Stack push 4 failed.");

	ret = stackPush(&myStack_1, 5);
	ASSERT((ret == 0), "Stack push 5 failed.");

	ret = stackPush(&myStack_1, 6);
	ASSERT((ret == -1), "Stack exhaustion failed.");
}

void __CUT__PushPopTest(void)
{
	int ret;
	int value;

	/* Test two pushes and then two pops */

	ret = stackPush(&myStack_2, 55);
	ASSERT((ret == 0), "Stack Push of 55 failed.");

	ret = stackPush(&myStack_2, 101);
	ASSERT((ret == 0), "Stack Push of 101 failed.");

	ret = stackPop(&myStack_2, &value);
	ASSERT((ret == 0), "Stack Pop failed.");
	ASSERT((value == 101), "Stack popped wrong value.");

	ret = stackPop(&myStack_2, &value);
	ASSERT((ret == 0), "Stack Pop failed.");
	ASSERT((value == 55), "Stack popped wrong value.");
}

void __CUT_TAKEDOWN__Explode(void)
{
	int ret;

	ret = stackDestroy(&myStack_1);
	ASSERT((ret == 0), "Stack 1 Destruction.");

	ret = stackDestroy(&myStack_2);
	ASSERT((ret == 0), "Stack 2 Destruction.");

	printf("\n\n Cut test for stack Complete!");
}
