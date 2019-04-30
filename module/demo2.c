//
// Created by Administrator on 2019/4/29.
//

#include <stdio.h>
#include <stdlib.h>
int main()
{
    //char *p;
    /**
     * 这里虽然定义了一个指针变量p
     * 但它本身并没有分配什么内存，导致不能装东西！
     */
    char *p = malloc(10* sizeof(char));
    /**
     *变量名称 p
     * 变量类型  char
     * 变量内容  某堆区的内存地址
     * 变量内存模型位置  栈区
     * 变量生命周期  函数出栈后就结束
     * 变量存储类型  自动
     * 变量大小  10个字节
     */
    scanf("%s\n",p);
    printf("%s\n",p);
    return 0;
}