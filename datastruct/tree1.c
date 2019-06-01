//
// Created by 1655664358@qq.com on 2019/5/31.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/***************树的双亲表示法***********************/
//每个结点存储数据本身，也会存储它的双亲结点位置
//用数组来存储每个结点


#define ERROR 0
#define OK 1
#define MAX_TREE_SIZE 100
typedef char TElemType;//结点的数据类型
typedef int Status;
typedef struct PTNode{ //结点结构
    TElemType data;//本身的数据
    int parent;//双亲位置
    int firstChild;//长子域位置
}PTNode;

typedef struct {  //树结构
    PTNode nodes[MAX_TREE_SIZE];//结点数组
    int r,n;//根结点和结点数量
}PTree;

Status insetNode(PTree *tree,char data,int parent,int fisrtChild);
Status removeNode(PTree *tree,int i,char *data);
Status showAllNode(PTree *tree);
Status test();
int main()
{

    PTNode node;
    node.data = 'A';//结点数据本身
    node.parent = -1;//结点的双亲节点位置
    node.firstChild = -1;//结点的长子位置

    PTree tree;
    tree.r=0;
    tree.n=1;
    tree.nodes[tree.r] = node;

    printf("%c\n",tree.nodes[tree.r].data);
    return 0;
}

Status test()
{
//    PTree tree;
//    PTNode node;
//    node.data='A';
//    node.parent=-1;
//
//    tree.nodes[0] = node;
//    tree.r=0;
//    tree.n=1;
//    printf("tree.nodes[0].data=%c\n",tree.nodes[0].data);
//
//    insetNode(&tree,'B',0);
//    printf("tree.nodes[1].data=%c\n",tree.nodes[tree.n-1].data);
//
//
//    insetNode(&tree,'C',0);
//    printf("tree.nodes[2].data=%c\n",tree.nodes[tree.n-1].data);
//    //双亲节点
//    printf("tree.nodes[2].data=%c\n",tree.nodes[tree.nodes[tree.n-1].parent].data);
//
//    insetNode(&tree,'D',1);
//    printf("tree.nodes[2].data=%c\n",tree.nodes[tree.n-1].data);
//
//    insetNode(&tree,'E',2);
//    printf("Me is %c\n",tree.nodes[tree.n-1].data);
//    printf("Parent is %c\n",tree.nodes[tree.nodes[tree.n-1].parent].data);
//
//    insetNode(&tree,'F',2);
//    printf("Me is %c\n",tree.nodes[tree.n-1].data);
//    printf("Parent is %c\n",tree.nodes[tree.nodes[tree.n-1].parent].data);
//
//    insetNode(&tree,'G',3);
//    printf("Me is %c\n",tree.nodes[tree.n-1].data);
//    printf("Parent is %c\n",tree.nodes[tree.nodes[tree.n-1].parent].data);
//
//    insetNode(&tree,'H',3);
//    printf("Me is %c\n",tree.nodes[tree.n-1].data);
//    printf("Parent is %c\n",tree.nodes[tree.nodes[tree.n-1].parent].data);
//
//    insetNode(&tree,'I',3);
//    printf("Me is %c\n",tree.nodes[tree.n-1].data);
//    printf("Parent is %c\n",tree.nodes[tree.nodes[tree.n-1].parent].data);
//
//    insetNode(&tree,'J',4);
//    printf("Me is %c\n",tree.nodes[tree.n-1].data);
//    printf("Parent is %c\n",tree.nodes[tree.nodes[tree.n-1].parent].data);
//
//    printf("***************************************************************\n");
//    showAllNode(&tree);
//
//    char data;
//    removeNode(&tree,6,&data);
//    printf("*************************remove some data**************************************\n");
//    showAllNode(&tree);
//    printf("remove data is %c\n",data);
}
Status insetNode(PTree *tree,char data,int parent,int fisrtChild)
{
    if (tree->n>MAX_TREE_SIZE){
        return ERROR;
    }
    PTNode node;
    node.data = data;
    node.parent = parent;
    tree->nodes[tree->n++] = node;
    return OK;
}

Status showAllNode(PTree *tree)
{
    int i=0;
    for(i=0;i<tree->n;i++){
        printf("Me is %c,Parent is %c\n",tree->nodes[i].data,tree->nodes[tree->nodes[i].parent].data);
    }
}

Status removeNode(PTree *tree,int i,char *data)
{
    int k;
    *data = tree->nodes[i-1].data;
    for(k=i;k<tree->n-1;k++){
        tree->nodes[k-1] = tree->nodes[k];
    }
    return OK;
}