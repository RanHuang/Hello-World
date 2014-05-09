/*****************************************************************************
 * Author	 : nick | work at XJTU-ylab.
 * Email	 : xjhznick@gmail.com
 * Last modified : 2014-05-09 21:10
 * Filename	 : 1_11.c
 * Description	 : Calulate the sum of an array of interger. 
 * ***************************************************************************/

#include "stdio.h"
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	
	printf("Sum = %d\n",arr_sum(a,10));
	printf("Sum by recursion = %d\n",arr_sum_recur(a,10));

	return 0;
}
/* for 
 * S(n0 = 0
 * */
int arr_sum(int arr[], int n)
{
	int i,tmpsum;
	tmpsum = 0;
	for(i = 0; i < n; i++)
		tmpsum += arr[i];
	return tmpsum;
}
/* recursion 
 * S(n) = 12n
 * arr[] 4
 * n     4
 * return address 4
 * */
int arr_sum_recur(int arr[], int n)
{
	if(n) return (arr_sum_recur(arr, n-1) + arr[n-1]);
	return 0;
}
