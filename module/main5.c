//
// Created by 1655664358@qq.com on 2019/5/1.
//
#include <stdio.h>
#include <stdlib.h>
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

int *age(int a,int b)
{
    int *c;
    *c=a+b;
    return c;
}
int main()
{
    int i;
    for(i=0;i<100;i++){
        sum();
    }
    printf("****************************\n");
    printf("n=%d\n",*(int *)(0X407030));

    int (*func)() = sum;
    func();
    printf("c=%d\n",*age(1,1));

    int *(*a)(int,int) = age;
    //printf("c1=%#X\n",*a(100,200));
    return 0;
}
