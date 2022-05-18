/*************************************************************************
	> File Name: testing.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 25 Sep 2015 11:21:51 AM CST
    > Description: 
 ************************************************************************/

#include <stdio.h>
#include "stack.h"

static int failed;

void checkResult(int testNum, int result)
{
	if(result == 0){
		printf("*** Failed test number %d\n", testNum);
		failed++;
	}else{
		printf("Test number %2d passed.\n", testNum);
	}
}
/*
 * A simple regression testing.
 */
void test1(void)
{
	stack_t myStack;
	int ret;
	
	failed = 0;

	ret = stackCreate(0, 0);
	checkResult(0, (ret == -1));

	ret = stackCreate(&myStack, 0);
	checkResult(1, (ret == -1));

	ret = stackCreate(&myStack, 65536);
	checkResult(2, (ret == -1));

	ret = stackCreate(&myStack, 1024);
	checkResult(3, (ret == 0));

	checkResult(4, (myStack.state == STACK_CREATED));

	checkResult(5, (myStack.index == 0));

	checkResult(6, (myStack.max == 1024));

	checkResult(7, (myStack.storage != (int *)0));

	ret = stackDestroy(0);
	checkResult(8, (ret == -1));

	ret = stackDestroy(&myStack);
	checkResult(9, (ret == 0));

	checkResult(10, (myStack.state != STACK_CREATED));

	if(failed == 0)
		printf("test1 passed.\n");
	else
		printf("test1 failed!\n");
}

int main()
{
	failed = 0;
	test1();

	return 0;
}
