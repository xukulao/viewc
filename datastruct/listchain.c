//
// Created by 1655664358@qq.com on 2019/5/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * 每个结点有数据域和指针域构成
 * 单链表：由N个结点【数据元素映像】链构成，每个结点有指针域指向下一个元素的存储位置，以便将线性表的数据元素按其逻辑次序连接在一起
 * 头结点【数据域不存储东西，或存储公共资料，头指针指向第一个元素的位置】
 * 头指针
 *
 */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;
typedef int Status;
Status GetElem(LinkList L,int i,ElemType *e);
Status LinkListInsert(LinkList L,int i,ElemType *e);
Status LinkListRemove(LinkList L,int i,ElemType *e);
Status showAllElem(LinkList L,int i);
void CreateListHead(LinkList L,int i);
void CreateListTail(LinkList L,int i);
int main()
{
//    Node student;
//    ListChain stuList;
//    stuList = &student;
//    stuList->data = 1;
//    Node student2;
//    student2.data = 2;
//    stuList->next = &student2;
//    printf("stuList.data=%d,stuList.next.data=%d\n",stuList->data,stuList->next->data);

//    Node student1;
//    Node student2;
//    Node student3;
//    Node student4;
//    Node student5;
//
//    student1.data = 100;
//    student2.data = 200;
//    student3.data = 300;
//    student4.data = 400;
//    student5.data = 500;
//
//
//    student1.next = &student2;
//    student2.next = &student3;
//    student3.next = &student4;
//    student4.next = &student5;
//    student5.next = NULL;
//    LinkList L;//头结点
//    Node student0;
//    student0.data = 6;
//    student0.next = &student1;
//    L = &student0;
//    //L->data = 5;
//    //L->next = &student1;
//
//    ElemType *e;
//    ElemType k;
//    e = &k;
//    GetElem(L,3,e);
//
//    printf("*************************************\n");
//    int a=80;
//    LinkListInsert(L,4,&a);
////    GetElem(L,4,e);
//
//    showAllElem(L,7);
//    printf("**************remove***********************\n");
//    LinkListRemove(L,2,e);
//    showAllElem(L,6);


    LinkList L;
    L = (LinkList)malloc(sizeof(Node));
   // L->next = NULL;
    int n=6;
    //CreateListHead(L,n);

    CreateListTail(L,n);
    showAllElem(L,n);

    return 0;
}

Status showAllElem(LinkList L,int i)
{
    int k=1;
    LinkList p;
    p = L;
    printf("p.data=%d\n",p->data);
    while(p&&k<i){
        p = p->next;
        printf("p.data=%d\n",p->data);
        k++;
    }
    if (!p||k>i){
        return ERROR;
    }
    return OK;
}
/**
 * 获取单链表的某个结点数据
 * @param L
 * @param i
 * @param e
 * @return
 */
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    j=1;
    LinkList p;//创建一个结点
    //p = L->next;//得到单链表头结点指向的第一个结点
    p = L;
    while(p&&j<i){
        p = p->next;//继续得到下一个结点
        j++;
    }
    if (!p||j>i){
        return ERROR;
    }
    *e = p->data;
    printf("your data is %d\n",*e);
    return OK;
}

/**
 * 单链表插入
 * @param L
 * @param i
 * @param e
 * @return
 */
Status LinkListInsert(LinkList L,int i,ElemType *e)
{
    int j;
    j=1;
    LinkList p,s;
    //p = L->next;//获取第一个结点
    p = L;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if (!p||j>i){
        return ERROR;
    }

    //创建新结点
    s = (LinkList)malloc(sizeof(Node));
    s->data = *e;//新结点要保存的数据
    s->next = p->next;//新结点保存后继数据元素的存储位置
    p->next = s;//保存当前创建的新结点

    return OK;
}

/**
 * 单链表结点移除
 * @param L
 * @param i
 * @param e
 * @return
 */
Status LinkListRemove(LinkList L,int i,ElemType *e)
{
    int j;
    j=1;
    LinkList p,q;
    p = L->next;//得到头结点指向的第一个结点
    while(p&&j<i){
        p=p->next;//结点向下循环
        j++;
    }

    if (!p||i>j){
        return ERROR;
    }

    q = p->next;//当前结点的下一个结点  要删除下一个结点
    p->next = q->next;//当前结点等于下一个结点的下一个结点

    return OK;

}

/**
 * 头插法创建整个结点
 * @param L
 * @param n
 */
void CreateListHead(LinkList L,int n)
{
    LinkList p;
    int i;
    srand(time(0));

    //L = (LinkList)malloc(sizeof(Node));
    //(L)->next = NULL;

    /**
     * 每次创建新结点的指针域都会保存链表的第一个结点
     * 而新结点都会作为链表的第一个结点
     */
    for(i=0;i<n;i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()*100+1;
        p->next = (L)->next;//L.next = 第一个元素
        (L)->next = p;//L.next指向的第一元素换成目前插入

    }
}

/**
 * 链表尾插入
 * @param L
 * @param n
 */
void CreateListTail(LinkList L,int n)
{
    LinkList p,r;
    int i;
    srand(time(0));

    r = L;
    for(i=0;i<n;i++){
        p = (LinkList)calloc(1,sizeof(Node));
        p->data = i;
        r->next = p;//单链表的最后一个是新结点p
        r = p;//表示当前链表的最后一个结点是新插入的p
    }
    r->next = NULL;
}