//
// Created by 1655664358@qq.com on 2019/5/28.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef int SElemType;
typedef int Status;
#define ERROR 0
#define OK 1
//链栈结构
typedef struct stackNode{
    SElemType data;
    struct stackNode *next;
}stackNode,*LinkStackPtr;

typedef struct linkStack{
    LinkStackPtr top;
    int count;
}linkStack;


int main()
{
    return 0;
}