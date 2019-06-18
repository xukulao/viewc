//
// Created by 1655664358@qq.com on 2019/6/18.
//


#include <stdlib.h>
#include <stdio.h>
typedef struct Link{
    char elem;
    struct Link *next;
}link;

link *initLink();
void display(link *p);
int main()
{

    link *p = initLink();
//    printf("p.elem=%d\n",p->elem);
//    printf("p.elem=%d\n",p->next->elem);
//    printf("p.elem=%d\n",p->next->next->elem);
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

void display(link *p)
{
    link *temp = p;
    while(temp){
        printf("%d\n",temp->elem);
        temp = temp->next;
    }
}