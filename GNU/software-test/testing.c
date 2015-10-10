/*************************************************************************
	> File Name: testing.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 25 Sep 2015 11:21:51 AM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
static int failed;

void checkResult(int testNum, int result)
{
	if(result == 0){
		print("*** Failed test number %d\n", testNum);
		failed++;
	}else{
		print("Test number %2d passed.\n", testNum);
	}
}
/*
 * A simple regression testing.
 */
void test1(void)
{

}

int main()
{
	failed = 0;
	test1();

	return 0;
}
