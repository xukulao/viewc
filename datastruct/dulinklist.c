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
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct Node{
    ElemType data;
    struct Node *piror;
    struct Node *next;
}Node *LinkList;

Status listInsert(LinkList L,int i,ElemType *e);
int main()
{
    return 0;
}

Status listInsert(LinkList L,int i,ElemType *e)
{

}