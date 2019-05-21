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
Status ListInsert(StaticLinkList L,int i,ElemType e);
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
//    printf("%d\n",Malloc_SLL(space));
//    printf("%d\n",Malloc_SLL(space));
//    printf("%d\n",Malloc_SLL(space));
//    printf("%d\n",Malloc_SLL(space));

    ListInsert(space,1,100);//
    ListInsert(space,2,200);//
    ListInsert(space,3,300);//
    ListInsert(space,4,400);//

    ListInsert(space,2,999);
    ListInsert(space,3,888);
    int k=0;
    for(k=1;k<=6;k++){
        if (space[k].data){
            printf("space[%d]=%d\n",k,space[k].data);
            //printf("sapce[%d].cur=%d\n",k,space[k].cur);
        }
    }

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

Status ListInsert(StaticLinkList L,int i,ElemType e) //4 400
{
    int j,k,l;
    k = MAXSIZE-1;//最后一个元素  //999
    if (i<1){
        return ERROR;
    }

    j = Malloc_SLL(L);  // 4
    //printf("j=%d\n",j);
    if(j){
        L[j].data = e;  //L[4].data = 400
        for(l=1;l<=i-1;l++){
            k = L[k].cur;  //k=4 L[3].cur=4
            printf("k=%d,L[%d].cur=%d\n",k,k,L[k].cur);

        }
        L[j].cur = L[k].cur; // L[4].cur = L[3].cur L[4].cur = 0
        L[k].cur = j;//L[3].cur = 4
        return OK;
    }
    return ERROR;

}