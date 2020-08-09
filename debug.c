//
// Created by Administrator on 2018/4/1
//
#include <stdio.h>

int main()
{
    int a = 1;

    int b = 10;
    int c = a+b;

    printf("c=%d,c=%#X\n",c,&c);
    printf("c=%p,c=%#X\n",c,&c);
    return 0;
}
