/*************************************************************************
	> File Name: sysconvert.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sun 19 Apr 2015 08:33:17 PM CST
	> Description: 实现任意进制整数的转换
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 64
int n2dec(char arr[], int base);
int dec2n(char arr[], int num, int base);
int alpha2upper(char arr[]);
void strTranspose(char str[]);
int main(int argc, char *argv[])
{
    char input[NUM], output[NUM];
    char str[NUM];
    int base_a, base_b;
    int num_dec;
  
    if(argc != 3){
	printf("Usage:  %s <A> to <B>\n", argv[0]);
	exit(1);
    }
    strcpy(str, argv[1]);
    base_a = n2dec(str, 10);
    base_b = n2dec(argv[2], 10);
    printf("Input a number(base-%d) and converted to a new number(base-%d)\n>>",
		base_a, base_b);

    scanf("%s", input);
    
    alpha2upper(input);
    if(base_a == base_b){
	printf("Output: %s(base-%d)\n", input, base_a);
    }else if(base_b == 10){
	num_dec = n2dec(input, base_a);
	printf("Output: %d(base-10)\n", num_dec);
    }else{
	dec2n(output, n2dec(input, base_a), base_b);
	printf("Output: %s(base-%d)\n", output, base_b); 
    } 

    return 0;
}

int alpha2upper(char arr[])
{
    int str_len, i;
    str_len = strlen(arr);
    if(str_len > NUM){
	printf("Error: Array bounds overflow!\n");
	exit(1);
    }
    for(i=0; i<str_len; i++){
	if('a'<=arr[i] && arr[i]<='z')
	    arr[i] = arr[i] - 'a' + 'A';
    }
    return 0;
}
int n2dec(char arr[], int base)
{
    int str_len, i;
    int num;
    int ret_dec;
    str_len = strlen(arr);
    for(i=0, ret_dec=0; i<str_len; i++){
	if('0'<=arr[i] && arr[i]<='9'){
	    num = arr[i] - '0';
	}else{
	    num = arr[i] - 'A' + 10;
	}
    	ret_dec += power(num, base, str_len-1 - i);
    }
    
    return ret_dec;
}
int power(int num, int base, int n)
{
    if(num && n){
 	while(n){
	    num *= base;
	    n--;
	}
    }
    return num;
}
int dec2n(char arr[], int num, int base)
{
    int remainder, i;
    i = 0;
    do{
    	remainder = num % base;
    	num /= base;
	if(remainder < 10)
	    arr[i] = remainder + '0';
	else
	    arr[i] = remainder-10 + 'A';
	i++;
    }while(num);
    arr[i] = '\0';
    strTranspose(arr);
    return 0;
}
void strTranspose(char str[])
{
    int i, j;
    char temp;
    i = 0;
    j = strlen(str) - 1;
    while(i<j){
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
	i++, j--;
    }
}
