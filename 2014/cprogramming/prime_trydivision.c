/*************************************************************************
	> File Name: prime_trydivision.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Tue 21 Apr 2015 09:25:31 AM CST
	> Description:试除法求解1000以内的素数(168个) , 100以内(25个)
 ************************************************************************/

#include<stdio.h>
#define NUMSIZE 100
int is_prime(int n);
int main(int argc, char *argv[])
{
	int i, count;
	for(count=0, i=2; i<NUMSIZE; i++){
		if(is_prime(i)){
			count++;
			printf("%-3d ", i);
			if(count%10 == 0) printf("\n");
		}
	}
	printf("\nTotal number of prime : %d\n", count);
	return 0;
}
int is_prime(int a)
{
	int i;

	if(a<=1) return 0; //<=1的数不是素数
/*
	int isPrime;

	isPrime = 1;
	for(i=2; i*i<=a; i++){
		if(a%i == 0){
			isPrime=0;
			break;
		}
	}
	return isPrime;
*/
	/*The lite edition of the above code block.*/
	for(i=2; i*i<=a; i++){
		if(a%i == 0){
			return 0;
		}
	}
	return 1;
}
