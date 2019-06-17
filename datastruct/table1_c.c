//
// Created by 1655664358@qq.com on 2019/6/17.
//

#include <stdlib.h>
#include <stdio.h>
#define SIZE 5
typedef struct Table{
    int *head;//数据
    int lenght;//当前元素个数
    int size;//总元素个数
}table;

table InitTable();
table addTable(table t,int elem,int add);
table delTable(table t,int add);
int selectTable(table t,int elem);
table updateTable(table t,int elem,int newElem);
void displayTable(table t);

int main()
{
    table t = InitTable();
    for(int i=1;i<=t.size;i++){
        t.head[i-1] = i;
        //*(t.head+i+1) = i;
        //t.head[i] = (int)(i+1);
        t.lenght++;
    }
    displayTable(t);
    t = addTable(t,6,3);
    t = addTable(t,7,4);
    displayTable(t);
    t = delTable(t,3);
    displayTable(t);

    t = updateTable(t,7,100);
    displayTable(t);
    return 0;
}

table InitTable()
{
    table t;
    t.head = (int *)malloc(SIZE*sizeof(int));//申请一段连续大小为SIZE的内存空间
    if (!t.head){
        printf("error");
    }
    t.size = SIZE;
    t.lenght = 0;
    return t;
}

table addTable(table t,int elem,int add)
{
    if(add>t.lenght+1||add<1){
        printf("add error!\n");
    }
    if (t.lenght==t.size){
        t.head = (int *)realloc(t.head,(t.size+1)* sizeof(int));
        if (!t.head){
            printf("realloc error!\n");
            return t;
        }
        t.size+=1;
    }

    for(int i=t.lenght-1;i>=add-1;i--){
        t.head[i+1] = t.head[i];
    }
    t.head[add-1] = elem;
    t.lenght++;
    return t;
}


table delTable(table t,int add)
{
    if(add>t.lenght||add<1){
        printf("del error\n");
    }
    for(int i=add;i<t.lenght;i++){
        t.head[i-1] = t.head[i];
    }

    t.lenght--;
    return t;
}

int selectTable(table t,int elem)
{
    for(int i=0;i<t.lenght;i++){
        if (elem==t.head[i]){
            return i+1;
        }
    }
    return -1;
}

table updateTable(table t,int elem,int newElem)
{
    int add = selectTable(t,elem);
    if (add!=-1){
        t.head[add-1] = newElem;
    }
    return t;
}
void displayTable(table t)
{
    for(int i=0;i<t.lenght;i++){
        printf("%d",*(t.head+i));
    }
    printf("\n");
}