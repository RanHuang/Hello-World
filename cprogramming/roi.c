/*************************************************************************
	> File Name: roi.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Tue 05 May 2015 09:18:08 AM CST
	> Description:　Calculate the Return On Investment
 ************************************************************************/

#include<stdio.h>
#include"selflib.h"
double ROI(double initial, double rate, int period);
int main()
{
	double initial_principal, t_principal;
	double rate;
	int period;

	int i;
	double pre_principal;
	printf("\t￥￥投资回报计算程序(复利)$$\n");
	initial_principal = getDouble("投资本金:");
	rate = getDouble("年回报率(%):");
	period = getInteger("投资期数：");
	
	t_principal = ROI(initial_principal, rate, period);
	printf("投资期结束之后的资金数：%.0f\n", t_principal);
	
	printf("\n期数\t本金\t利润\t本利合计\n");
	t_principal = initial_principal;
	for(i=1; i<=period; i++){
		pre_principal = t_principal;
		t_principal = ROI(initial_principal, rate, i);
		printf("%d\t%.0f\t%0.f\t%0.f\n",
				i, pre_principal, t_principal - pre_principal, t_principal);
	}

	printf("\n\t**End!**\n");
	return 0;
}

double ROI(double initial_principal, double rate, int period)
{
	int i;
	double t_principal;
	t_principal = initial_principal;
	rate = rate/100.0;
	for(i=0; i<period; i++){
		t_principal *= (1 + rate);
	}
	return t_principal;
}
