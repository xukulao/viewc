//
// Created by 1655664358@qq.com on 2019/5/24.
//
/**
 * 栈：即限定在某一端能进行插入和删除【栈顶】表尾操作的线性表
 * 出栈【弹栈】：删除数据元素
 * 进栈【入栈，压栈】：插入数据元素
 * 空栈
 * 栈顶，栈底
 * 后进先出Last In First Out LIFO结构
 *
 */
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

/**
 * 双栈空间初始化
 * 双栈空间实现说明
 * 栈1
 * 栈底为-1
 * 栈顶为n-1
 *
 * 栈2
 * 栈底为n
 * 栈顶为0
 *
 * 栈1满栈是n-1
 * 栈2满栈是0
 *
 * -1 0 1 2 3 4 5 top1 | top2 0 1 2 3 4 5
 * 栈1压栈时从-1开始累加，到达4时，则4+1=5 栈1满栈
 * 栈2压栈时从5开始累减，到达0时，则-1+1=0 栈2满栈
 */
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;

}SqDoubleStack;

Status push(SqStack *s,SElemType *e);
//双栈空间操作方法
Status DoublePush(SqDoubleStack *s,SElemType *e,int stackNumber);
Status DoublePop(SqDoubleStack *s,SElemType *e,int stackNumber);

Status pop(SqStack *s,SElemType *e);
void showAll(SqStack *s);
void showAllDobuleStack(SqDoubleStack *s);
int main()
{

    //初始化一个空栈
//    SqStack *s = (SqStack *)malloc(sizeof(SqStack));
//    s->top=-1;
//    int *k=(int *)calloc(1, sizeof(int));
//
//    *k = 200;
//
//    push(s,k);//压栈
//    push(s,k);
//
//    showAll(s);
//    int m=9;
//    push(s,&m);
//    showAll(s);
//
//    printf("pop some data from stack\n");
//    int *e = (int *)malloc(sizeof(int));
//    pop(s,e);
//    printf("e=%d\n",*e);
//    free(k);


    SqDoubleStack *s = (SqDoubleStack*)malloc(sizeof(SqDoubleStack));
    s->top1 = -1;//栈底 做为始端
    s->top2 = MAXSIZE;//1000
    SqDoubleStack *s1 = (SqDoubleStack*)calloc(1, sizeof(SqDoubleStack));
    s1->top2 = MAXSIZE;//栈底  做为未端
    s1->top1 = -1;

    int k = 100;
    int stackNumber=1;
    DoublePush(s,&k,stackNumber);//栈1入栈
    DoublePush(s1,&k,2);//栈1入栈

    printf("s=%d\n",s->data[s->top1]);
    printf("s=%d\n",s1->data[s1->top2]);

    DoublePush(s,&k,stackNumber);
    k = 900;
    DoublePush(s,&k,stackNumber);

    showAllDobuleStack(s);
    int m;

    DoublePop(s,&m,1);
    printf("m=%d\n",m);

    return 0;
}

void showAllDobuleStack(SqDoubleStack *s)
{
    int i;
    if (s->top1!=-1){
        for(i=0;i<=s->top1;i++){
            printf("s->data[%d]=%d\n",i,s->data[i]);

        }
    }else{
        printf("it's null stack!");
    }
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

/**
 * 双栈空间压栈操作
 * @param s
 * @param e
 * @param stackNumber
 * @return
 */
Status DoublePush(SqDoubleStack *s,SElemType *e,int stackNumber)
{

    /**
     * 从栈1开始累加，到达999时，栈1满栈
     * 从栈2开始累减，到达0时，s->top1=-1 +1 =0 = s->top2[top2是减]
     */
    if (s->top1+1==s->top2){
        return ERROR;
    }
    if (stackNumber==1){
        s->data[++s->top1] = *e;//从-1开始累加
    }else if(stackNumber==2){
        s->data[--s->top2] = *e;//从1000开始累减
    }
    return OK;
}

/**
 * 双栈弹栈
 * 取出元素时会先检测双栈空间否有数据即是否达到栈底了
 * @param s
 * @param e
 * @param stackNumber
 * @return
 */
Status DoublePop(SqDoubleStack *s,SElemType *e,int stackNumber)
{
    if (stackNumber==1){
        if (s->top1==-1){//是否到栈底了
            return ERROR;
        }
        *e = s->data[s->top1--];//栈1弹栈
    }else if(stackNumber==2){
        if (s->top2==MAXSIZE){//是否到栈底了
            return ERROR;
        }
        *e = s->data[s->top2++];//栈2弹栈
    }

    return OK;

}