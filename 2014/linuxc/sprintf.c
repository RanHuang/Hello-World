/*************************************************************************
	> File Name: sprintf.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月12日 星期四 18时22分03秒
  > Description: 使用sprintf函数进行整数or浮点数转换为字符串和字符串拼接操作
 ************************************************************************/

#include<stdio.h>

int main()
{
	char buf[20];
	char *str1 = "I like ";
	char *str2 = "Linux C.";

	sprintf(buf, "%f", 3.141592653); 
	//注：只能显示小数点后六位，且第六位经过四舍五入
	puts(buf);


	sprintf(buf, "%s%s", str1, str2);
	puts(buf);

	return 0;
}

	
