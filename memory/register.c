//
// Created by Administrator on 2019/4/26.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    register int a = 10;
    /**
     * 类型存储类别  通用的工作寄存器组
     * 存储位置  cpu的通用工作寄存器
     * 可能会分配
     */
     printf("a=%d,a=%#X\n",a,&a);
    return 0;
}