//
// Created by 1655664358@qq.com on 2014/5/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define china main
typedef int japanese;
#define class struct

class person{
    int age;
    char sex[4];
    char address[20];
};

union {
    int n;
    char ch;
}data;
/**
 * char int float double 指针都可以
 * @return
 */
japanese china(int arg,char *argv)
{
    data.n = 1234;//0x000003
    //小端  4个字节 低位存储在地字节  高位存储在高字节
    /**
     * 00000000 00000000 00000000 00000011
     * 11111111 11111111 11111111 11111100
     * 11111111 11111111 11111111 11111101 10 a 11 b 12 c 13 d
     *
     * d -3
     * x ff ff ff fd
     */

    printf("data.n=%#X,data.n=%d\n",&data.n,data.n);
    printf("data=%#X,data size=%d\n",&data, sizeof(data));
    printf("data.ch=%#X,data.ch=%d\n",&data.ch,data.ch);

    printf("data.n=%#x\n",data.n);
    return 0;
}
