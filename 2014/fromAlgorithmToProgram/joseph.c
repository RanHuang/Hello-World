/*************************************************************************
	> File Name: joseph.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Thu 16 Jul 2015 10:34:37 PM CST
    > Description: 
		Joseph problem
		1..k, k+1...K+k(n = 2*k)
		make the last k person (k...n) to be executed fist
		among n person, the every mth is going to be excuted.
 ************************************************************************/

#include<stdio.h>
int joseph(int k);

int main(int arc, char* argv[])
{
	int k;
	printf("input k(0 - quit): ");
	scanf("%d", &k);
	while(k){
		printf("k = %d\n", k);
		printf("m = %d\n", joseph(k));	
		printf("input k(0 - quit): ");
		scanf("%d", &k);
	}

	return 0;
}

int joseph(int k)
{
	int a, b, i, j, m, n, t;
	
	a = 1;
	while(1){
		for(b=1; b<=k; b++){
			n = 2*k;
			m = a*k+b;
			t = 0;
			for(i=1; i<=k; i++){
				t = (t+m-1)%n;
				if(t<k) break;
				printf("&&&--%d\n", t);
				n--;
			}
			if(i>k) return m;
		}
		a += 2;
	}
}
