//
// Created by 1655664358@qq.com on 2019/6/3.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/***************树的孩子表示法【含双亲表示法】***********************/
//每个结点的指针域会指向每棵子树的根结点
//每棵子树的所有孩子用链表存储
//每个结点保存孩子的链表头指针
//每个结点保存自己的双亲位置


#define ERROR 0
#define OK 1
#define MAX_TREE_SIZE 100
typedef int Status;
typedef char TElemType;//结点的数据类型
typedef struct CTNode{  //孩子结点
    int child;
    struct CTNode *next;
}*ChildPtr;


typedef struct {  //表结点
    TElemType data;//结点本身的数据
    int parent;//结点的双亲域
    ChildPtr firstChild;//结点的孩子域头指针
}CTBox;

typedef struct {  //树结点
    CTBox nodes[MAX_TREE_SIZE];
    int r,n;
}CTtree;

Status insertNode(CTtree *tree,int data);
int main()
{
    return 0;
}

Status insertNode(CTtree *tree,int data)
{

}