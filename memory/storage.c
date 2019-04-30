//
// Created by Administrator on 2019/4/26.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int i,result;
    for(i=0;i<100;i++){
        result = sum(i);
    }
    printf("result %d\n",result);
    printf("result =%d\n",*(int *)(0X407030));
    system("pause");
    return 0;
}

int sum(int n)
{
    static int result =0;
    /**
     * 变量名称 result
     * 变量类型 int
     * 存储类别 static
     * 内存存储位置  静态存储区  整个生命周期有效
     * 变量初始值 0
     * 变量地址  对应应用程序的虚拟地址【由操作系统负责虚拟地址和物理地址的转换】
     * 变量有效期 一直有效
     */
    result+=n;
   // printf("result=%d\n",result);
     printf("result=%#X",&result);
    return result;
}