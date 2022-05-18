/*************************************************************************
	> File Name: daytime_client.c
	> Author: Nick
	> Mail: xjhznick@gmail.com 
	> Created Time: Thu 30 Jul 2015 09:33:00 PM CST
    > Description: 
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<time.h>

#define MAX_LINE 128

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int server_sock;
	struct sockaddr_in server_addr;

	char message[MAX_LINE + 1];
	int str_len = 0;
	int index = 0;
	int limit = MAX_LINE;

	if(3 != argc){
		printf("Usage : %s <IP> <Port> \n", argv[0]);
		exit(1);
	}

	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(-1 == server_sock){
		error_handling("socket() error!");
		exit(1);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_port = htons(atoi(argv[2]));

	if( -1 == connect(server_sock, (struct sockaddr*)&server_addr,
					  sizeof(server_addr)) ){
		error_handling("connect() error!");
	}

	while((str_len = read(server_sock, &message[index], limit))>0){
		index += str_len;
		limit -= str_len;
	}
	message[index] = 0;

	printf("Message from server : %s", message);

	close(server_sock);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
