//
// Created by 1655664358@qq.com on 2019/5/14.
//

#include <stdio.h>

/**
 * 线性表的顺序存储结构
 * data 线性表的存储起始位置
 * length 线性表的当前长度
 * MAXSIZE 线性表的最大长度
 */
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];//线性表的起始位置
    ElemType length;//线性表目前的长度
}SqList;

SqList test;
void initList();
Status getElem(SqList L,int i,ElemType *e);//获取线性表里的元素
Status insertList(SqList L,int i,ElemType *e);
Status deleteList(SqList L,int i,ElemType *e);

//线性表的占用存储单元为：c=LOC(ai+1)=LOC(ai)+c
//LOC(ai)=LOC(a1)+(n-1)*c 第一个元素占用的存储单元+所占用的存储单元为第i个元素所占用的存储单元
int age[10] = {34,23,11,98,43,92,33,87,29,76};
//23 34 j = 0 --23 34 11 98 43 92 33 87 29 76
//11 34 j = 1 --23 11 34 98 43 92 33 87 29 76
//34 98 j = 2 --23 11 34 98 43 92 33 87 29 76
//43 98 j = 3 --23 11 34 43 98 92 33 87 29 76
//92 98 j = 4 --23 11 34 43 92 98 33 87 29 76
//33 98 j = 5 --23 11 34 43 92 33 98 87 29 76
//87 98 j = 6 --23 11 34 43 92 33 87 98 29 76
//29 98 j = 7 --23 22 34 43 92 33 87 29 98 76
//76 98 j = 8 --23 22 34 43 92 33 87 29 76 98


void Bubble();
void insertArray(int num1[],int k,int id,int data);
int main()
{
    initList();//创建一个线性表

    int status;
    ElemType *e;
    int data;
    e = &data;
    status = getElem(test,12,e);
    printf("status=%d,e=%d,list of lent =%d\n",status,*e,test.length);
//    printf("*****************************************\n");
//    Bubble();
//    printf("*****************************************\n");
//    int num1[10] = {1,2,3,4,5,6,7,8};
//    //insertArray(num1,5,1,10);
//    insertArray(num1,5,0,199);

    data = 88;
    //int insert = insertList(test,5,e);
    int delete = deleteList(test,5,e);

    return 0;
}

Status getElem(SqList L,int i,ElemType *e)
{
    if(L.length==0||i<1||i>L.length){
        return ERROR;
    }
    *e = L.data[i-1];
    return OK;
}

/**
 * 向线性表里插入数据元素
 * @param L
 * @param i
 * @param e
 * @return
 */
Status insertList(SqList L,int i,ElemType *e)
{
    int k;
    if(L.length==MAXSIZE){
        return ERROR;
    }
    if (i<1||i>L.length){
        return ERROR;
    }
    if (i<L.length){
        for(k=L.length;k>=i-1;k--){
            L.data[k+1]=L.data[k];
        }
    }
    L.data[i-1] = *e;
    L.length++;

    for(i=0;i<L.length;i++){
        printf("test.data[%d]=%d\n",i,L.data[i]);
    }

    return OK;
}

Status deleteList(SqList L,int i,ElemType *e)
{
    int k;
    if (L.length==0){
        return ERROR;
    }
    if (i<1||i>L.length){
        return ERROR;
    }
    *e = L.data[i-1];
    if(i<L.length){
        for(k=i;k<L.length;k++){
            L.data[k-1] = L.data[k];
        }
    }
    L.length--;
    int j;
    for(j=0;j<L.length;j++){
        printf("L.data[%d]=%d\n",j,L.data[j]);
    }
    printf("remove elem is %d\n",*e);
    return OK;
}

void initList()
{
    int i=0;
    for(i;i<MAXSIZE-10;i++){
        test.data[i] = i;
    }
    test.length = MAXSIZE-10;
}

void Bubble()
{
    int i,j;
    int temp;
    for(i=0;i< 10-1;i++){
        for(j=0;j<10-1-i;j++){
            if(age[j]>age[j+1]){
                temp = age[j];
                age[j] = age[j+1];
                age[j+1] = temp;
            }
        }
    }
    for(i=0;i<10;i++){
        printf("age[%d]=%d\n",i,age[i]);
    }
}

void insertArray(int num1[],int k,int id,int data)
{
    int num2[11];
    int i;
    if (id==1){
        for(i=0;i<10;i++){
            if (i<k){
                num2[i] = num1[i];
            }else if(i>k){
                num2[i-1] = num1[i];
            }
        }

    }else if(id==0){
        for(i=0;i<10;i++){
            if(i<k){//5 4
                num2[i] = num1[i];
            }else if(i>k){//6
                num2[i+1] = num1[i];
            }else { // 5
                num2[i+1] = data;
                num2[i] = num1[i];
            }
        }
    }

    for(i=0;i<10;i++){
        num1[i] = num2[i];
    }
    for(i=0;i<10;i++){
       printf("num[%d]=%d\n",i,num1[i]);
    }

}