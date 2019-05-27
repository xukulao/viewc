#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#define FALSE 0
#define TRUE 1
static int stop = FALSE;

static void handle_term(int sig)
{
    stop = TRUE;
}

int main(int argc,char *argv[])
{
    signal(SIGTERM,handle_term);  //信号监听
    if (argc>=3){
        printf("useage:%s ip_address port _number backog\n",basename(argv[0]));

    }
    const char *ip = argv[1];

    int port = atoi(argv[2]);//将字符转换为整数
    int backlog = atoi(argv[3]);
    int sock = socket(PF_INET,SOCK_STREAM,0);//创建一个socket PF_INET为协议族  SOCKET_STREAM为服务类型
    assert(sock>=0);//声明  为false报错=

    struct sockaddr_in address;//tcp/ipv4地址

    bzero(&address,sizeof(address));//地址清零
    address.sin_family = AF_INET;//tcp/ipv4地址族 跟协议族对应

    inet_pton(AF_INET,ip,&address.sin_addr);//将输入的点分十进制ip地址转换为二进制，并保存在地址
    address.sin_port = htons(port);
    int ret = bind(sock,(struct sockaddr *)&address,sizeof(address));//绑定地址

    assert(ret!=-1);

    ret = listen(sock,backlog);//监听socket 进入LISTEN状态

    assert(ret!=-1);

    while(!stop){
        sleep(1);//当用户按下终止时如ctrl+c,信号会被程序捕获到
    }

    close(sock);//关闭socket

    return 0;
}
