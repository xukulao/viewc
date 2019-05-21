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
int Malloc_SLL(StaticLinkList space);
int main()
{
//    Component test;
//    test.data=100;
//    test.cur = 1;
//    printf("test.data=%d\n",test.data);
//
//    StaticLinkList person;
//    person[0].data = 1000;
//    person[0].cur = 1;
//    person[1].data = 2000;
//    printf("person[1].data=%d\n",person[1].data);

    StaticLinkList space;
    InitList(space);
    printf("%d\n",Malloc_SLL(space));
    printf("%d\n",Malloc_SLL(space));
    printf("%d\n",Malloc_SLL(space));
    printf("%d\n",Malloc_SLL(space));

    return 0;
}

/**
 * 静态链表初始化  当前元素的下标存储了后继元素的下标即地址
 * @param space
 * @return
 */
Status InitList(StaticLinkList space)
{
    int i;
    for(i=0;i<MAXSIZE-1;i++){
        space[i].cur = (i+1);
    }
    space[MAXSIZE-1].cur = 0;
    return OK;
}

int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;//得到第一个元素的下标  i =1  space[0].cur=2 i =2 space[0].cur=3 i=3
    if(space[0].cur){
        space[0].cur = space[i].cur;//得到第二个元素的下标 假设i为第一个元素，它的cur保存的是第二个元素的下标  space[1].cur=2 space[2].cur=3
    }
    return i;
}