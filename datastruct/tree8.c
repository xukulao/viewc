//
// Created by 1655664358@qq.com on 2019/6/6.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
typedef int Status;
typedef char TElemType;//结点的数据类型

//二叉树结点定义
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status createBinaryTree(BiTree tree);
void PreOrderTraverse(BiTree tree);
void InOrderTraverse(BiTree tree);
void PostOrderTraverse(BiTree tree);
int main()
{
    BiTree tree = malloc(sizeof(BiTNode));
    //构建一个二叉链树
    createBinaryTree(tree);
    printf("**************************\n");
    PreOrderTraverse(tree);
    printf("\n**************************\n");
    InOrderTraverse(tree);
    printf("\n**************************\n");
    PostOrderTraverse(tree);
    return 0;
}

/**
 * 二叉链树前序遍历 【根，左，右】
 * @param tree
 * @return
 */
void PreOrderTraverse(BiTree tree)
{
    if (tree==NULL){
        return ;
    }
    printf("%c",tree->data);
    PreOrderTraverse(tree->lchild);
    PreOrderTraverse(tree->rchild);
}

/**
 * 二叉链树中序遍历 【左，根，右】
 * @param tree
 * @return
 */
void InOrderTraverse(BiTree tree)
{
    if (tree==NULL){
        return ;
    }

    PreOrderTraverse(tree->lchild);
    printf("%c",tree->data);
    PreOrderTraverse(tree->rchild);
}

/**
 * 后序遍历  【左，右，根】
 * @param tree
 */
void PostOrderTraverse(BiTree tree)
{
    if (tree==NULL){
        return ;
    }

    PreOrderTraverse(tree->lchild);
    PreOrderTraverse(tree->rchild);
    printf("%c",tree->data);
}

Status createBinaryTree(BiTree tree)
{
    tree->data = 'A';

    BiTree nodeB = malloc(sizeof(BiTNode));
    nodeB->data = 'B';

    tree->lchild = nodeB;

    BiTree nodeC = malloc(sizeof(BiTNode));
    nodeC->data = 'C';
    nodeC->lchild = NULL;
    nodeC->rchild = NULL;

    tree->rchild = nodeC;

    BiTree nodeD = malloc(sizeof(BiTNode));
    nodeD->data = 'D';
    nodeD->lchild = NULL;
    nodeD->rchild = NULL;

    BiTree nodeE = malloc(sizeof(BiTNode));
    nodeE->data = 'E';
    nodeE->rchild = NULL;
    nodeE->lchild = NULL;

    nodeB->lchild = nodeD;
    nodeB->rchild = nodeE;
    BiTree nodeH = malloc(sizeof(BiTNode));
    nodeH->data = 'H';
    nodeH->lchild=NULL;
    nodeH->rchild =NULL;

    nodeD->lchild = nodeH;

    BiTree nodeK = malloc(sizeof(BiTNode));
    nodeK->data = 'K';
    nodeK->lchild = NULL;
    nodeK->rchild = NULL;

    nodeH->rchild = nodeK;

    BiTree nodeF = malloc(sizeof(BiTNode));
    nodeF->data = 'F';
    nodeF->lchild = NULL;
    nodeF->rchild = NULL;

    BiTree nodeG = malloc(sizeof(BiTNode));
    nodeG->data = 'G';
    nodeG->lchild = NULL;
    nodeG->rchild = NULL;


    nodeC->lchild = nodeF;
    nodeC->rchild = nodeG;

    BiTree nodeI = malloc(sizeof(BiTNode));
    nodeI->data = 'I';
    nodeI->lchild = NULL;
    nodeI->rchild = NULL;


    BiTree nodeJ = malloc(sizeof(BiTNode));
    nodeJ->data = 'J';
    nodeJ->lchild = NULL;
    nodeJ->rchild = NULL;


    nodeF->lchild = nodeI;
    nodeG->rchild = nodeJ;


}