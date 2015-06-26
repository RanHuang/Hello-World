/*************************************************************************
	> File Name: complexexpression.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月16日 星期一 14时54分54秒
  > Description:
 ************************************************************************/

#include <stdio.h>
 
int main(){
    int i = 0;
    int a[] = {10,20,30};
	 
    int r = 1 * a[i++] + 2 * a[i++] + 3 * a[i++];
    printf("%d\n", r);
    return 0;
}
