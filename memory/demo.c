//
// Created by Administrator on 2019/4/21.
//

#include <stdio.h>

struct test{
    int a;
    char b;
    int c;
}t={1,'c',2};
int main(void)
{
//    int a = 10;
//    int b = 20;
//    printf("a=%#X,b=%#X\n",&a,&b);
//    /**
//     * 打印变量的内存地址并不是真的内存物理地址，而是虚拟地址，会由操作系统管理内存完成
//     * 相互切换
//     *
//     * 程序运行时，操作系统会完成虚拟地址和物理的内存映射
//     */

     //内存地址 对齐
     printf("%d,%d,%d,%d\n", sizeof(t.a), sizeof(t.b), sizeof(t.c), sizeof(t));
     printf("%#X,%#X,%#X,%#X\n", &t.a, &t.b, &t.c, &t);
    return 0;
}