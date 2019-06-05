//
// Created by 1655664358@qq.com on 2019/6/4.
//
/**
 * 树的孩子兄弟表示法
 * 每个结点都有自己的孩子，每个孩子都会有自己的兄弟【二叉树】
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
typedef int Status;
typedef char TElemType;//结点的数据类型

//树的孩子兄弟表示法结构【二叉树】
typedef struct CSNode{
    TElemType data;
    struct CSNode *firstChild,*rightsib;
}CSNode ,*CSTree;
Status insertFirstChildNode(CSTree tree,int i,char data,int type);//给当前节点添加第一个儿子
Status insertRightSib(CSTree tree,int treei,int broi,char data,int type);//给当前节点添加兄弟
int main()
{

    CSTree tree;
    CSNode node;
    node.data = 'A';
    node.firstChild = NULL;
    node.rightsib = NULL;
    tree = &node;
    insertFirstChildNode(tree,1,'B',1);
    insertRightSib(tree,1,1,'C',2);
    insertFirstChildNode(tree,1,'E',2);
    insertRightSib(tree,1,1,'F',2);

    insertFirstChildNode(tree,2,'D',1);
    insertFirstChildNode(tree,3,'G',1);
    insertRightSib(tree,3,1,'H',2);
    insertRightSib(tree,3,2,'I',2);


    printf("children is %c,bro is %c\n",tree->firstChild->data,tree->rightsib->data);
    printf("children is %c\n",tree->firstChild->firstChild->data);
    printf("children is %c\n",tree->firstChild->firstChild->firstChild->data);
    printf("bro is %c\n",tree->firstChild->firstChild->rightsib->data);
    printf("bro is %c\n",tree->firstChild->firstChild->rightsib->rightsib->data);

    return 0;
}

Status getNode(CSTree tree,int i,CSTree node)
{
    CSTree p,t;
    t = tree;
    int k=1;
    while(t&&k<i){
        t = t->firstChild;
        k++;
    }
    if(!t||k>i){
        return ERROR;
    }
    node = t;
    return OK;
}
Status insertFirstChildNode(CSTree tree,int i,char data,int type)
{
    CSTree p,t;
    t = tree;
    int k=1;
    while(t&&k<i){
        t = t->firstChild;
        k++;
    }
    if(!t||k>i){
        return ERROR;
    }
    p = (CSTree)malloc(sizeof(CSNode));
    p->data = data;
    if (type==1){
        p->firstChild = t->firstChild;
        t->firstChild = p;
    }else{
        p->firstChild = t->rightsib->firstChild;
        t->rightsib->firstChild = p;
    }
    return OK;
}

Status insertRightSib(CSTree tree,int treei,int broi,char data,int type)
{
    CSTree p,t;
    t = tree;
    int k=1;
    while(t&&k<treei){
        t = t->firstChild;
        k++;
    }
    if(!t||k>treei){
        return ERROR;
    }

    k = 1;
    if (type==1){ //兄弟链基础上添加
        while(t&&k<broi){
            t = t->rightsib;
            k++;
        }
        if(!t||k>broi){
            return ERROR;
        }
        p = (CSTree)malloc(sizeof(CSNode));
        p->data = data;
        p->rightsib = t->rightsib;
        t->rightsib = p;
    }else{

        p = (CSTree)malloc(sizeof(CSNode));
        p->data = data;
        p->rightsib = t->rightsib;
        t->rightsib = p;

    }

    return OK;
}
