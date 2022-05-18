/*************************************************************************
	> File Name: exactfloatvalue.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月13日 星期五 11时01分31秒
  > Description: 计算分数精确值
	由于计算机内部表达方式的限制，浮点运算都有精度问题，为了得到高精度的计算结果，就需要自己设计实现方法。
(0,1)之间的任何浮点数都可以表达为两个正整数的商，为了表达这样两个数的商，可以将相除的结果存放在一维数组中，数组的每个元素存放一位十进制数字。即商的第一位存放在第一个元素中，第二位存放在第二个元素中，以此类推，就可以用数组来表达一个高精度的除法结果了。
如16/19的结果0.8421052631...就可以依次存放8、4、2、1、0、5、2、6、3、1...在数组中。
而除法的过程，则可以模仿人工列竖式做除法的方式，先将被除数乘以10，得到一位商以后，将余数乘以10作为下一轮计算的被除数：
    160/19->8余8
	80/19->4余4
	...
	某次余数为0时，则表明除尽。
	现在，请写一个程序，输入一个分数，计算出它的小数形式。无论是否可以除尽，输出最多小数点后200位。
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#define MAXSIZE 200

int main(int argc, char *argv[])
{
	char quotient[MAXSIZE + 1];
	int a,b,i,remainder;

	memset(quotient, 0, sizeof(quotient));

	while(1){
		printf("Input 'a/b', to calculate a/b(10 =< a < b < 100):\n");
		scanf("%d/%d", &a, &b);
		if(a>=10 && b<100 && a<b) break;
	}

	i = 0;
	remainder = a;
	while(remainder && i<200){
		remainder *= 10;
		quotient[i++] = remainder/b + '0';
		remainder %= b;
	}
/*
	do{
		a *= 10;
		quotient[i++] = a/b + '0';
		remainder = a%b;
		a = remainder;
		
	}while(remainder && i<200);
	*/
	printf("0.%s\n", quotient);

	return 0;
}

