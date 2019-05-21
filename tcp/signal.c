//
// Created by 1655664358@qq.com on 2019/5/21.
//

#include <stdio.h>
#include <stdlib.h>//标准库
#include <signal.h>//信号
#include <unistd.h>//时间
#include <assert.h>//声明
#include <string.h>
void sigHandler(int signo);

int main(int argc,char *argv[])
{
//    signal(SIGINT,sigHandler);
//    while(1)
//    {
//        sleep(1);
//    }

    int age = atoi(argv[1]);
    printf("age=%d\n",age);
    //getchar();
   // assert(1);
    int k=100;
    printf("k=%d\n",*&k);
    bzero(&k, sizeof(k));//清空
    return 0;
}

void sigHandler(int signo)
{
    if (signo==SIGINT){
        printf("received SIGINT\n");
    }
}