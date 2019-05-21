//
// Created by 1655664358@qq.com on 2019/5/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
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
    getchar();
    return 0;
}

void sigHandler(int signo)
{
    if (signo==SIGINT){
        printf("received SIGINT\n");
    }
}