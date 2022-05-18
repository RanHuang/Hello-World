/*************************************************************************
	> File Name: test_embunit.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Thu 15 Oct 2015 04:48:33 PM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include"embUnit/embUnit.h"
#include"stack.h"

stack_t myStack;

static void setUp(void)
{
	printf("setUp called!\n");
}

static void tearDown(void)
{
	printf("tearDown called.\n");
}

static void testInit(void)
{
	int ret;

	ret = stackCreate(&myStack, 5);
	TEST_ASSERT_EQUAL_INT(0, ret);
}

static void testPushPop(void)
{
	int ret, value;

	ret = stackPush(&myStack, 55);
	TEST_ASSERT_EQUAL_INT(0, ret);

	ret = stackPush(&myStack, 101);
	TEST_ASSERT_EQUAL_INT(0, ret);

	ret = stackPop(&myStack, &value);
	TEST_ASSERT_EQUAL_INT(0, ret);
	TEST_ASSERT_EQUAL_INT(101, value);

	ret = stackPop(&myStack, &value);
	TEST_ASSERT_EQUAL_INT(0, ret);
	TEST_ASSERT_EQUAL_INT(55, value);
}

static void testStackDestroy(void)
{
	int ret;

	ret = stackDestroy(&myStack);
	TEST_ASSERT_EQUAL_INT(0, ret);
}

TestRef StackTest_tests(void)
{
	/* 创建表示独立的单元测试的数组(fixtures) */
	EMB_UNIT_TESTFIXTURES(fixtures){
		new_TestFixture("testInit", testInit),
		new_TestFixture("testPushPop", testPushPop),
		new_TestFixture("testStackDestroy", testStackDestroy),
	};
	/* 创建表示单元测试集合的数组(StackTest) */
	EMB_UNIT_TESTCALLER(StackTest, "StackTest", setUp, tearDown, fixtures);

	return (TestRef)&StackTest;
}

int main(int argc, const char *argv[])
{
	TestRunner_start();
	TestRunner_runTest(StackTest_tests());
	TestRunner_end();

	return 0;
}
