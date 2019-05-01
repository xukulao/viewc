//
// Created by 1655664358@qq.com on 2019/5/1.
//
#include <stdio.h>
#include <stdlib.h>
int *age(int * ,int *);
int sum()
{
    static int n=0;
    /**
     * 变量  地址的助记符号
     * 类型  静态int
     * 内容 0
     * 存储类别  static
     * 内存模型  全局数据区
     * 存储周期 整个程序周期有效
     * 变量地址  0X407030
     *
     * 链接器会根据该符号找到内存地址组合成一个可执行程序
     */
    n++;
    printf("n=%d\n",n);
    printf("n of address %#X\n",&n);
    return n;
}

int *age(int *a,int *b)
{
   int *c;
   int c1;
   c = &c1;
   *c=*a+*b;
   return c;
}
int main()
{
    int i;
//    for(i=0;i<100;i++){
//        sum();
//    }
//    printf("****************************\n");
//    printf("n=%d\n",*(int *)(0X407030));
//
//    int (*func)() = sum;
//    func();
    //printf("c=%d\n",*age(1,1));

    //int *(*ageN)(int,int) = age;
    //x(int x,int y)
    //printf("c1=%#X\n",*ageN(100,200));
    //int *result = *age(10,20);
    //printf("age=%d\n",*result);
    //printf("age=%d\n",*age(199,2));
    //printf("age=%d\n",*age(100,200));
//    int *a;
//    int *b;
//    int a1=10;
//    int b1=20;
//    a=&a1;
//    b=&b1;
//    *b=100;
//    //printf("age=%d",age(a,b));
//    printf("a=%#X,a=%d,b=%#X,b=%d\n",a,*a,b,b1);

    int a1=10;
    int b1=10;
    int *a,*b;
    a=&a1;
    b=&b1;
    printf("age=%d\n",*age(a,b));
    a1=100;
    b1=200;
    printf("age=%d\n",*age(a,b));

    int *(*ageNum)(int *,int *) = age;
    a1=1000;
    b1=2000;
    printf("ageNum=%d\n",*ageNum(a,b));
    a1=20;b1=20;
    printf("ageNum=%d\n",*&*ageNum(a,b));
    return 0;
}
