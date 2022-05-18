/*************************************************************************
	> File Name: printf_example.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Fri 17 Jul 2015 09:32:42 PM CST
    > Description: 
		printf转换说明的可选项，使用效果演示
 ************************************************************************/

#include<stdio.h>
int main(void)
{
	printf("%#x\n", 0xff);
	printf("%x\n\n", 0xff);

	printf("%#o\n", 076);
	printf("%o\n\n", 076);

	printf("-%10s-\n", "hello");
	printf("-%-*s-\n\n", 10, "hello");

	printf("%.4s\n", "hello");
	printf("-%6.4d-\n", 100);
	printf("-%*.*f-\n\n", 8, 4, 3.14);

	/*
	 * d i o u x X -- int型参数
	 * hh h l ll -- 改变字长，char, short, long, long long
	 * d i -- 有符号数
	 * o u x X -- 无符号数
	 * o -- 八进制
	 * u -- 十进制
	 * x -- 十六进制小写 abcdef
	 * X -- 十六进制大写 ABCDEF
	 * [L] e E f -- double型参数 , L e -- long double
	 */
	printf("%hhu\n\n", -1);

	printf("%.4d\n\n", 100);

	printf("%#X\n\n", 0xdeadbeef);

	printf("%c\n\n", 256+'A');
	/*
	 * void *型参数格式化
	 */
	printf("%p\n\n", main);
	/*
	 * f -- [-]ddd.ddd格式化double型参数，默认6位精度
	 */
	printf("%f\n", 3.14);
	printf("%f\n\n", 0.00000314);
	/*
	 *e -- [-]d.ddde[+-]dd
	 */
	printf("%e\n\n", 3.14);

	printf("%g\n", 3.00);
	printf("%g\n\n", 0.00001233456);
	/* 打印 ‘%’ */
	printf("%%\n");
	return 0;
}
