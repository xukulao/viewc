//
// Created by 1655664358@qq.com on 2019/5/15.
//

#include <stdio.h>
union{
    int n;
    char ch;
    short int m;
}data;
void main()
{
    data.n = 0x00000001;
    printf("data.n=%#X\n",data.n);
    printf("data.ch=%d\n",data.ch);
    printf("data.m=%d\n",data.m);
    printf("%f.5",1/3);
}