/*************************************************************************
	> File Name: gethostbyname.c
	> Author: xjhznick
	> Mail: xjhznick@gmail.com 
	> Created Time: 2015年03月20日 星期五 09时47分46秒
  > Description:利用域名获取IP地址
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>

void error_handling(char *message);

int main(int argc, char *argv[])
{
	struct hostent *host;
	int i;

	if(2 != argc){
		printf("Usage : %s <addr>\n", argv[0]);
		exit(1);
	}

	//通过域名获取IP
	host = gethostbyname(argv[1]);
	if(!host){
		error_handling("gethostbyname error!");
	}

	//官方域名
	printf("Official name : %s \n", host->h_name);
	//同一个IP可以绑定多个域名，除官方域名外的其他域名
	for(i=0; host->h_aliases[i]; i++){
		printf("Aliases %d : %s \n", i+1, host->h_aliases[i]);
	}
	//gethostbyname函数支持IPv4和IPv6，如是IPv4,则变量值为AF_INET
	printf("Address type : %s \n", 
			(host->h_addrtype==AF_INET)?"AF_INET":"AF_INET6");
	//域名对应的IP地址
	for(i=0; host->h_addr_list[i]; i++){
		printf("IP Addr %d : %s \n", i+1, 
				inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
	}

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
