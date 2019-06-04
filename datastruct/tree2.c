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
typedef struct CTNode
{  //孩子结点
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
}CTree;

Status insertNode(CTree *tree,int data,int parent,ChildPtr firstChild);
Status removeNode(CTree *tree,int i,CTBox *box);
Status insertChildLink(ChildPtr firstChild,int i,int data);
Status removeChildLink(ChildPtr firstChild,int i,int *data);
Status showAllChildNode(ChildPtr firstChild);

void createNodeTree(CTree *tree);
void test();
int main()
{
    /**
     * 0 A parent=-1 child=1,2
     * 1 B parent=0 child=3
     * 2 C parent=0 child=4,5
     * 3 D parent=1 child=6,7,8
     * 4 E parent=2 child=9
     * 5 F parent=2 child=-1
     * 6 G parent=3 child=-1
     * 7 H parent=3 child=-1
     * 8 I parent=3 child=-1
     * 9 J parent=4 child=-1
     */

    CTree tree;
    createNodeTree(&tree);
    printf("%c\n",tree.nodes[0].data);
    printf("%3c\n",tree.nodes[tree.nodes[0].firstChild->next->child].data);
    printf("%3c\n",tree.nodes[tree.nodes[0].firstChild->next->next->child].data);

    int i;

    for(i=0;i<tree.n;i++){
        printf("%c ---- %c\n",tree.nodes[i].data,tree.nodes[tree.nodes[i].parent].data);
        if (tree.nodes[i].firstChild->next!=NULL){
            ChildPtr p;
            p = tree.nodes[i].firstChild;
            printf("\n-------");
            while(p){
                p = p->next;
                if (p){
                    printf("%c",tree.nodes[p->child].data);
                }

            }
            printf("\n");
        }
    }

    printf("attempt remove a elem\n");
    CTBox box;
    removeNode(&tree,9,&box);
    printf("box.data=%d\n",box.data);
    return 0;
}

void createNodeTree(CTree *tree)
{
    ChildPtr firstChild = malloc(sizeof(struct CTNode));
    firstChild->child = -1;
    firstChild->next = NULL;
    insertChildLink(firstChild,1,1);
    insertChildLink(firstChild,2,2);
    insertNode(tree,'A',-1,firstChild);

    ChildPtr firstChild1 = malloc(sizeof(struct CTNode));
    firstChild1->child = -1;
    firstChild1->next = NULL;
    insertChildLink(firstChild1,1,3);
    insertNode(tree,'B',0,firstChild1);

    ChildPtr firstChild2 = malloc(sizeof(struct CTNode));
    firstChild2->child = -1;
    firstChild2->next = NULL;
    insertChildLink(firstChild2,1,4);
    insertChildLink(firstChild2,2,5);
    insertNode(tree,'C',0,firstChild2);


    ChildPtr firstChild3 = malloc(sizeof(struct CTNode));
    firstChild3->child = -1;
    firstChild3->next = NULL;
    insertChildLink(firstChild3,1,6);
    insertChildLink(firstChild3,2,7);
    insertChildLink(firstChild3,3,8);
    insertNode(tree,'D',1,firstChild3);

    ChildPtr firstChild4 = malloc(sizeof(struct CTNode));
    firstChild4->child = -1;
    firstChild4->next = NULL;
    insertChildLink(firstChild4,1,9);
    insertNode(tree,'E',2,firstChild4);

    ChildPtr firstChild5 = malloc(sizeof(struct CTNode));
    firstChild5->child = -1;
    firstChild5->next = NULL;
    insertNode(tree,'F',2,firstChild5);

    ChildPtr firstChild6 = malloc(sizeof(struct CTNode));
    firstChild6->child = -1;
    firstChild6->next = NULL;
    insertNode(tree,'G',3,firstChild6);

    ChildPtr firstChild7 = malloc(sizeof(struct CTNode));
    firstChild7->child = -1;
    firstChild7->next = NULL;
    insertNode(tree,'H',3,firstChild7);

    ChildPtr firstChild8 = malloc(sizeof(struct CTNode));
    firstChild8->child = -1;
    firstChild8->next = NULL;
    insertNode(tree,'I',3,firstChild8);

    ChildPtr firstChild9 = malloc(sizeof(struct CTNode));
    firstChild9->child = -1;
    firstChild9->next = NULL;
    insertNode(tree,'J',4,firstChild9);

}
Status showAllChildNode(ChildPtr firstChild)
{
    ChildPtr p;
    p = firstChild;
    int k=0;
    if (p==NULL||p->next==NULL){
        return ERROR;
    }
    while(p){
        p = p->next;
        if (p){
            printf("child = %d\n",p->child);
        }

    }

    return OK;
}
void test()
{
    printf("*************************************\n");

    ChildPtr firstChild = malloc(sizeof(struct CTNode));
    firstChild->child = -1;
    firstChild->next = NULL;

    insertChildLink(firstChild,1,100);
    insertChildLink(firstChild,2,200);
    insertChildLink(firstChild,3,300);
    showAllChildNode(firstChild);
    int data;
    removeChildLink(firstChild,3,&data);
    printf("*************************************\n");
    showAllChildNode(firstChild);


    ChildPtr child=malloc(sizeof(struct CTNode));
    struct CTNode node;
    CTBox box;
    box.data = 'A';
    box.parent = -1;

    node.child=1;
    node.next = NULL;

    child->next=&node;

    box.firstChild = child;

    CTree tree;
    tree.nodes[0] = box;
    tree.r = -1;
    tree.n = 1;

    printf("tree[0] %c\n",tree.nodes[0].data);
}
Status insertNode(CTree *tree,int data,int parent,ChildPtr firstChild)
{
    if (tree->n>=MAX_TREE_SIZE){
        return ERROR;
    }
    CTBox box;
    box.data = data;
    box.parent = parent;
    box.firstChild = firstChild;
    tree->nodes[tree->n++] = box;

    return OK;
}

Status removeNode(CTree *tree,int i,CTBox *box)
{
    if(tree->n==0){
        return ERROR;
    }
    int k;
    box = &tree->nodes[i];
    for(k=i;k<tree->n-1;k++){
        tree->nodes[k-1] = tree->nodes[k];
    }
    return OK;
}

Status insertChildLink(ChildPtr firstChild,int i,int data)
{
    ChildPtr temp = malloc(sizeof(struct CTNode));
    ChildPtr p = firstChild;
    int k=1;
    while(p&&k<i){
        p = p->next;
        k++;
    }
    if (!p||k>i){
        return ERROR;
    }
    temp->child = data;
    temp->next = p->next;
    p->next = temp;
    return OK;
}

Status removeChildLink(ChildPtr firstChild,int i,int *data)
{
    int k=1;
    ChildPtr p = firstChild;
    ChildPtr q;
    while(p&&k<i){
        p = p->next;
        k++;
    }
    if (!p||k>i){
        return ERROR;
    }

    q = p->next;
    p->next = q->next;
    return OK;

}