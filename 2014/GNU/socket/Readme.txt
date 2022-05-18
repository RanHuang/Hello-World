
套接字时使用相同协议的两个终点的联合体。

网络字节序--大端字节序
API:
int socket(int domain, int type, int protocol);
domain - IPV4: AF_INET
type   - TCP : SOCK_STREAM
	   - UDP : SOCK_DGRAM
protocol - 通常为0，一般只有流类型和数据报类型的通信有特殊协议

时间服务器程序：
$gcc -o a.out daytime_server.c -Wall
$./a.out <port>
使用telnet简单测试服务器程序
$telnet localhost <port>


$gcc -o client daytime_client.c -Wall
$gcc -o server daytime_server.c -Wall
$./server 23456
$./client 127.0.0.1 23456

SCTP--Stream Control Transmission Protocol
	结合了TCP的可靠性和UDP的组帧消息，并具备新的特点，如multi-homing(内送流量备援), multi-streaming(多重串流)
	内送流量备援在出现连接失败时提供更高的可用性。
