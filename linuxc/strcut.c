/*************************************************************************
	> File Name: strcut.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月22日 星期日 09时46分46秒
  > Description:

 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_SIZE 81
int main(int argc, char *argv[])
{
	char s1[BUF_SIZE], s2[BUF_SIZE], sret[BUF_SIZE];
	char *p;
	int s2_len, idx, pidx, end;
	int sret_idx;

	scanf("%s", s1);
	scanf("%s", s2);

//	printf("s1 : %s\n", s1);
//	printf("s2 : %s\n", s2);

	s2_len = strlen(s2);
	p = (char*)malloc(s2_len + 1);
	p[s2_len] = 0;

	memset(sret, 0, sizeof(sret));
	end = strlen(s1) - s2_len + 1;
	sret_idx = 0;
	pidx = 0;
	for(idx=0; idx<end; ){
		strncpy(p, s1+idx, s2_len);
//		printf("p : %s\n", p);
		if(!strcmp(p, s2)){
//			puts("\tMatched!\n");
//			printf("sret_idx = %d, pidx = %d, idx = %d\n", sret_idx, pidx, idx);
			strncpy(sret+sret_idx, s1+pidx, idx-pidx);
			sret_idx += idx-pidx;
			idx = idx+s2_len;
			pidx = idx;
//			printf("sret : %s\n", sret);
		} else{
			idx++;
		}
	}
	strncpy(sret+sret_idx, s1+pidx, (idx-1)+s2_len-pidx);
	sret_idx += (idx-1)+s2_len-pidx;
	
	sret[sret_idx] = 0;
	puts(sret);

	free(p);
	return 0;
}
