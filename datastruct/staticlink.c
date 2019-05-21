//
// Created by 1655664358@qq.com on 2019/5/21.
//
//静态链表
#include <stdio.h>
#define MAXSIZE 1000
typedef int ElemType;
typedef struct
{
    ElemType data;
    int cur;
}Component,StaticLinkList[MAXSIZE];
int main()
{
    Component test;
    test.data=100;
    test.cur = 1;
    printf("test.data=%d\n",test.data);

    StaticLinkList person;
    person[0].data = 1000;
    person[0].cur = 1;
    person[1].data = 2000;
    printf("person[1].data=%d\n",person[1].data);
    return 0;
}