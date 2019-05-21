//
// Created by 1655664358@qq.com on 2019/5/21.
//
//静态链表
//用数组来实现单链表
//data保存数据元素本身，而cur存储该元素的后继元素的下标即next指针
#include <stdio.h>
#define MAXSIZE 1000
typedef int ElemType;
typedef int Status;
#define OK 1
#define ERROR 0
typedef struct
{
    ElemType data;
    int cur;
}Component,StaticLinkList[MAXSIZE];
Status InitList(StaticLinkList space);
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

Status InitList(StaticLinkList space)
{
    int i;
    for(i=0;i<MAXSIZE;i++){
        space[i].cur = i+1;
    }
    space[MAXSIZE-i].cur = 0;
    return OK;
}