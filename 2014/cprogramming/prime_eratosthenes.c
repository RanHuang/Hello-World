/*************************************************************************
	> File Name: prime_eratosthenes.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Tue 21 Apr 2015 09:44:20 AM CST
	> Description: 使用Eratosthenes方法求素数
	筛选，筛去2,3,5,7的倍数..., 剩下的即为素数
 ************************************************************************/

#include<stdio.h>
#define NUMSIZE 1000
int main(int argc, char *argv[])
{
	int prime[NUMSIZE+1];
	int i, j, count;
	int bound;
	bound = NUMSIZE;
	/*Initialize:假定>=2的数都为prime，通过筛选找出非质数，置0
	 * prime      - 1
	 * none-prime - 0
	 */
	for(i=2; i<=bound; i++)
		prime[i] = 1;
	
	/*Core Algorithm*/
	for(i=2; i*i<=bound; i++){
		if(prime[i]){
			for(j=i*i; j<=bound; j++){
				if(prime[j] == 0) continue;
				if(j%i== 0) prime[j] = 0;
			}
		}
	}
	
	/*Count & Print*/
	count = 0;
	for(i=2; i<=bound; i++){
		if(prime[i]){
			count++;
			printf("%4d ", i);
			if(count%10 == 0) printf("\n");
		}
	}
	printf("\nTotoal number of prime is : %d\n", count);
	return 0;
}
