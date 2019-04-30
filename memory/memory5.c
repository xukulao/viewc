//
// Created by Administrator on 2019/4/26.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p = (char *)malloc(1000000*sizeof(char));//申请了100个字节的内存
    //malloc会向操作系统批发一大块内存进行管理
    //程序只是从内存池里取100个内存
    //当free释放的时候malloc会自动处理空闲的内存

    //1k=1000byte
    //1m=1000kb*10000
    int size = 1000000*10000;
    p = (char *)malloc(size*sizeof(char));//又申请了500个字节的内存
    //500Byte 0.5k的内存了  前面申请的内存由于没有指针变量指向它
    //导致占用了资源

    printf("p of size %d\n", sizeof(p));
    free(p);
    p = NULL;
    system("pause");
    return 0;
}