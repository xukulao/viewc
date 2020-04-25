//
// Created by 1655664358@qq.com on 2019/5/23.
//
/**
 * 双向链表
 * 双向循环链表
 * 每个节点的next指针域保存下一下的结点存储位置
 * 每个节点的prior指针域保存上一个结点的存储位置
 *
 * 每个结点有1个数据域和2个指针域
 *
 * 同时未端结点指针域会指向头结点
 *
 * 头结点指针域指向未端结点
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
typedef char ElemType;
typedef int Status;
typedef struct Node{
    char address[50];
    struct Node *piror;
    struct Node *next;
}Node,*LinkList;



//双向循环链表插入
Status listInsert(LinkList L,int i,ElemType *e);
//双向循环链表移除
Status listRmove(LinkList L,int i);
void showAllElem(LinkList L);
int main()
{

    LinkList L;
    L = (LinkList)malloc(sizeof(Node));
    LinkList Node1 = (LinkList)calloc(1, sizeof(Node));
    LinkList Node2 = (LinkList)calloc(1, sizeof(Node));

    strcpy(Node1->address,"shanghai");
    Node1->next = Node2;
    Node1->piror = L;

    strcpy(Node2->address,"beijing");
    Node2->next = L;
    Node2->piror = Node1;


    strcpy(L->address,"0");
    L->next = Node1;
    L->piror = Node2;


    int i=1;
    listInsert(L,i,"shanghai");

    printf("address=%s\n",L->address);
    printf("address 1 =%s\n",L->next->address);
    printf("address 2 =%s\n",L->next->next->address);
    printf("address 3 =%s\n",L->next->next->next->address);
    printf("address 4 =%s\n",L->next->next->next->next->address);

    listInsert(L,i,"japanese");
    //showAllElem(L);

    listInsert(L,i,"american");

    listRmove(L,1);
    showAllElem(L);
    return 0;
}

void showAllElem(LinkList L)
{
    LinkList  p;
    p = L;
    while(p){
        p = p->next;
        printf("next address=%s\n",p->address);
    }
}
Status listInsert(LinkList L,int i,ElemType *e)
{
    LinkList p,s;
    int k=0;
    p = L;
    while(p&&k<i){
        p = p->next;
        k++;
    }

    s = (LinkList)malloc(sizeof(Node));
    strcpy(s->address,e);

    s->piror = p;  //当前结点的前驱结点
    s->next = p->next;//当有结点的后继结点
    p->next->piror=s;//后继结点的前驱结点
    p->next = s;//前驱结点的后继结点

//    printf("p.next.address=%s\n",p->next->address);
//    printf("1 p.next.address=%s\n",p->next->next->address);
//    printf("2 p.next.address=%s\n",p->next->next->next->address);
//    printf("3 p.next.address=%s\n",p->next->next->next->next->address);
//    printf("4 p.next.address=%s\n",p->next->next->next->next->next->address);
//    printf("5 p.next.address=%s\n",p->next->next->next->next->next->next->address);
//    //free(s);
//    printf("6 p.next.address=%s\n",p->next->next->next->next->next->next->next->address);
//    printf("7 p.next.address=%s\n",p->next->next->next->next->next->next->next->next->address);
//    printf("8 p.next.address=%s\n",p->next->next->next->next->next->next->next->next->next->address);
    return OK;

}

Status listRmove(LinkList L,int i)
{
    LinkList p;
    int k=0;
    p = L;
    while(p&&k<i){
        p = p->next;
        k++;
    }

    p->piror->next = p->next;//当前结点的前驱结点的下一个结点
    p->next->piror = p->piror;//当前结点的后继结点的前驱结点

    return OK;
}
