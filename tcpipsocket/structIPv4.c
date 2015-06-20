struct sockaddr_in
{
	sa_family_t		sin_family;		//地址族(Address Family)
	uint16_t		sin_port;		//16位TCP/UDP端口号
	struct in_addr	sin_addr;		//32位IP地址
	char			sin_zero[8];	//不使用
};

struct in_addr
{
	in_addr_t		s_addr;			//32位IP地址
};
//扩展性计
in_addr_t	uint32_t
in_port_t	uint16_t

int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);//->成功返回0，失败-1

if( -1 == bind( server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) ){
		error_handling("bind() error");
	}

struct sockaddr
{
	sa_family_t		sin_family;		//地址族
	char			sa_data[14];	//地址信息
}

#include<arpa/inet.h>
in_addr_t inet_addr(const char *string); //->成功返回32位大端序整型值，失败 INADDR_NONE
int inet_aton(const char *string, struct in_addr *addr); //->成功返回1(true)，失败0(false)
char *inet_ntoa(struct in_addr addr); //->成功返回转换的字符串IP地址，失败-1