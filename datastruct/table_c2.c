//
// Created by 1655664358@qq.com on 2019/6/20.
//

#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 6
/**
 * 静态链表：使用数组【顺序表】+游标【类似链表指向下一个后继元素】
 * 1、创建一个静态链表
 * 2、存储时获取一个备用节点
 *
 * 存储上：取得数组的第一个元素的游标为A,再取得数组的第二个元素的游标为B
 *        并将A作为数组的下标【其游标域】存储B
 *        同时将B作数组的下标【其数据域】存储数据
 */
typedef struct {
    int data;//数据域
    int cur;//游标
}component;

int reserveArr(component *array);
int mallocArr(component *array);
int initArr(component *array);
void display(component *array,int body);
int main()
{
    component array[MAXSIZE];
    int body = initArr(array);
    printf("result\n");
    display(array,body);
    return 0;
}

int reserveArr(component *array)
{
    //创建一个备用的静态链表：
    /**
     * a[0] |-1,1|
     * a[1] |-1,2|
     * a[2] |-1,3|
     * a[3} |-1,4|
     * a[4] |-1,5|
     * a[5] |-1,0|
     */
    for(int i=0;i<MAXSIZE;i++){
        array[i].cur=i+1;
        array[i].data=-1;
    }
    array[MAXSIZE-1].cur = 0;
}

int mallocArr(component *array)
{
    int i = array[0].cur;//得到第0个数据元素的游标为1
    if(array[0].cur){
        array[0].cur = array[i].cur;//将第0个数据元素的游标设置为第2个数据元素的游标值
    }
    return i;
}

int initArr(component *array)
{
    reserveArr(array);
    int body = mallocArr(array);//取得第一个游标
    int tempBody = body;                                       //1
    for(int i=1;i<4;i++){
        int j = mallocArr(array);//取得第二个游标为2              //2            //3            //4
        array[tempBody].cur=j;//第1个数据元素的游标指向2           //a[1].cur=2   //a[2].cur=3   //a[3].cur=4
        array[j].data=i;//第二个数据元素的值 a[2]=1 a[3]=2 a[4]=3 //a[2].data=1  //a[3].data=2  //a[4].data=3
        tempBody=j;//为2                                       //tb=2         //tb=3         //tb=4
    }
    array[tempBody].cur=0;
    return body;
}

void display(component *array,int body)
{
    int tempBody = body;                                            //1
    while(array[tempBody].cur){
        printf("%d %d\n",array[tempBody].data,array[tempBody].cur);  //a[1].data a[1].cur
        tempBody = array[tempBody].cur;                              //tempBody=2
    }
    printf("%d %d\n",array[tempBody].data,array[tempBody].cur);
}