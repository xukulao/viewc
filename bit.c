//
// Created by Administrator on 2018/4/1

#include <stdio.h>

int main()
{

    /**
     * 位域 限制数据位数长度
     */
    struct {
        unsigned int m;//4个字节  32位
        unsigned int n:4;//4位
        unsigned char k:8;//1个字节8位
        unsigned int led:1;//1位
        unsigned char h:2;//只能是2位 0000 00001 0010 0011

    }a = {0xffffffff,0xE,'@',1,3};//0xffffffff 正好32位  0xE正好4位 0100 0011 0010 0001

    //

    printf("m=%#X,n=%X,k=%c,led=%d,h=%d\n",a.m,a.n,a.k,a.led,a.h);

    a.m = 9;//100
    printf("%d\n",a.m);

    struct {
        unsigned int m1;
        unsigned :20;//无名位域
        unsigned char m2;
    } b = {};

    return 0;
}
