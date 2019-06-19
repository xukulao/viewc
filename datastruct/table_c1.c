//
// Created by 1655664358@qq.com on 2019/6/18.
//


#include <stdlib.h>
#include <stdio.h>
/**
 * 链表结构
 * 链表是使用N个结点【数据域|指针域指向后继元素】构成的
 * 链表使用注意事项：插入，删除，修改，查找时特别注意当然链表到底在第几个数据元素上
 */
typedef struct Link{
    char elem;
    struct Link *next;
}link;

link *initLink();
link *insertElem(link *l,int elem,int add);  //链表插入
link *delElem(link *l,int add);//链表删除
int searchElem(link *l,int elem);//查找
link *updateElem(link *l,int elem,int add);//更新链表
void display(link *p);
int main()
{

    link *p = initLink();
//    printf("p.elem=%d\n",p->elem);
//    printf("p.elem=%d\n",p->next->elem);
//    printf("p.elem=%d\n",p->next->next->elem);
    display(p);
    p = insertElem(p,8,3);
    printf("*********************\n");
    display(p);
    p = delElem(p,2);
    printf("***********remove data**********\n");
    display(p);
    printf("****************search data\n");
    int index = searchElem(p,2);
    printf("%d\n",index);
    printf("*******************update data \n");
    p = updateElem(p,6,2);
    display(p);
    return 0;
}

link *initLink()
{
    link *p=NULL;
    link *temp = (link*)malloc(sizeof(link));
    temp->elem = 1;
    temp->next = NULL;

    p = temp;

    for(int i=2;i<=3;i++){
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;//p.next=a  |p|a|
        //temp = a;//temp = temp->next
        temp = temp->next;

    }
    return p;
}

link *insertElem(link *l,int elem,int add)
{
    link *p= l;
    for(int i=1;i<add;i++){
        if (p==NULL){
            printf("insert error\n");
            return p;
        }
        p = p->next;//1|2|3|4|5
    }

    link *c = (link *)malloc(sizeof(link));
    c->elem = elem;
    c->next = p->next;
    p->next = c;
    return l;
}

link *delElem(link *l,int add)
{
    link *temp =l;
    for(int i=1;i<add;i++){
        temp = temp->next;
    }

    link *del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return l;
}

int searchElem(link *l,int elem)
{
    link *p = l;
    int i=1;
    while(p->next){
        p = p->next;
        if (p->elem == elem){
            return i;
        }
        i++;
    }
    return -1;
}

link *updateElem(link *l,int elem,int add)
{
    link *p = l;
    p = p->next;
    for(int i=1;i<add;i++){
        p = p->next;
    }
    p->elem = elem;
    return l;
}
void display(link *p)
{
    link *temp = p;
    while(temp){
        printf("%d\n",temp->elem);
        temp = temp->next;
    }
}