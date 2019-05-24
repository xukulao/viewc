//
// Created by 1655664358@qq.com on 2019/5/24.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef int SElemType;
typedef int Status;
#define ERROR 0
#define OK 1
typedef struct {
    SElemType data[MAXSIZE];
    int top;
}SqStack;

Status push(SqStack *s,SElemType *e);
Status pop(SqStack *s,SElemType *e);
void showAll(SqStack *s);
int main()
{

    //初始化一个空栈
    SqStack *s = (SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
    int *k=(int *)calloc(1, sizeof(int));

    *k = 200;

    push(s,k);//压栈
    push(s,k);

    showAll(s);
    int m=9;
    push(s,&m);
    showAll(s);

    printf("pop some data from stack\n");
    int *e = (int *)malloc(sizeof(int));
    pop(s,e);
    printf("e=%d\n",*e);
    free(k);
    return 0;
}

void showAll(SqStack *s)
{
    int i;
    if (s->top!=-1){
        for(i=0;i<=s->top;i++){
            printf("s->data[%d]=%d\n",i,s->data[i]);

        }
    }else{
        printf("it's null stack!");
    }
}
/**
 * 进栈  入栈  压栈  从栈顶压栈
 * @param s
 * @param e
 * @return
 */
Status push(SqStack *s,SElemType *e)
{
    if (s->top==MAXSIZE-1){
        return ERROR;
    }

    s->top++;
    s->data[s->top] = *e;
    return OK;
}

/**
 * 从栈顶弹栈  出栈
 * @param s
 * @param e
 * @return
 */
Status pop(SqStack *s,SElemType *e)
{
    if (s->top==-1){
        return ERROR;
    }
    *e = s->data[s->top];
    s->top--;
    return OK;
}