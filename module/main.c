//
// Created by Administrator on 2019/4/20.
//
/**
 * 符号将多个模块拼接为一个独立的程序的过程就叫做链接（Linking）。
 * 变量，函数名等仅是内存地址的助记符号
 * 编译后最终全部转换为内存地址
 * 程序=代码+数据
 * 指令  操作数据的地址
 * 指令【代码】决定要做什么逻辑处理，如加法逻辑处理，移位等
 * 数据：内存地址上的数据
 * cpu从内存取出指令，取出数据，指令会送入到通用工作寄存器组，再送入ALU处理
 */
#include <stdio.h>
extern void func();
int n = 20;
extern int m;
int main()
{
    func();
    printf("n=%d,m=%d\n",n,m);
    return 0;
}