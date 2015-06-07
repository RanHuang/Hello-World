/*************************************************************************
	> File Name: facBigData.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Sat 25 Apr 2015 09:39:40 PM CST
	> 使用数组进行大整数阶乘计算，最大可计算 2^(sizeof(int)*8)/10的阶乘
	> 注意：其中使用log10()函数估算结果的位数，新版本的gcc在编译时需要添加
	  -lm 参数链接数学库。
	  e.g $gcc -o output file.c -lm
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int carry(int bit[], int highest_position);
int highestPosition(int array[], int n);

int main(int argc, char *argv[])
{
	int num, highest_pos, sum_bit;
	double sum;
	int* num_array;
	int i, j;
	printf("Input N to calculate N!.\n>>");
	scanf("%d", &num);
	//初步估算阶乘结果的位数
	for(i=2, sum=0; i<=num; i++){
		sum += log10(i);
	}
	sum_bit = (int)sum + 1;
	
	num_array = (int*)malloc((sum_bit+1)*sizeof(int));
	num_array[0] = 1;
	for(i=1; i<=sum_bit; i++) //所有数位初始化
		num_array[i] = 0;

	highest_pos = highestPosition(num_array, sum_bit);
	for(i=1; i<=num; i++){
		for(j=0; j<=highest_pos; j++)
			num_array[j] *= i;

		highest_pos = carry(num_array, highest_pos);
	}

	//Display the result.
	highest_pos = highestPosition(num_array, sum_bit);
	printf("The result of %d! is:\n", num);
	for(i=highest_pos, j=0; i>=0; i--){
		j++;
		printf("%d", num_array[i]);
		if(j>=30){
			printf("\n");
			j = 0;
		}else if(j%3 == 0) printf(" ");
	}
	printf("\nThe total number of result is %d.\n", highest_pos+1);
	free(num_array);
	return 0;
}
int highestPosition(int array[], int n)
{
	while(!array[n-1]) n--;
	return n-1;
}
int carry(int bit[], int highest_position)
{
	int i, carry_bit;
	carry_bit = 0;
	for(i=0; i<=highest_position; i++){ //依次保留个位，向高位进位
		bit[i] += carry_bit;
		carry_bit = bit[i]/10;
		bit[i] = bit[i]%10;
	}
	while(carry_bit){ //处理最高位，如果最高位 >9
		highest_position++;
		bit[highest_position] = carry_bit%10;
		carry_bit = carry_bit/10;
	}

	return highest_position;
}
