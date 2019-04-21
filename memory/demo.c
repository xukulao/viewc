//
// Created by Administrator on 2019/4/21.
//

#include <stdio.h>
/**
 * CPU由ALU,寄存器【大量的触发器构成，触发器具有存储功能，输出的结果输入的二进制信号影响
 * 同时没有输入时，输出的状态是保持的具有记忆功能】
 *
 * 寄存器组【多少位cpu】会存储二进制数据和代码
 *
 * 程序存储器：存储用户编写的程序代码
 * 数据存储器：存储数据
 * 指令寄存器：存储指令，每执行一条时会自动取下一条指令，取的数据来自于程序存储器
 * 指令译码器：【可以了解一下编码器和译码器的原理】，输入的指令会被译码出具体的指令
 * 译码出的指令会送传到ALU逻辑运算单元【加法器，计数器，移位，等大量的逻辑电路】
 * ALU：是一个大规模支持与，或，非，异或，加法，计数，移位等逻辑运算的超大规模逻辑电路
 * 他们由与门，或门【最小单元】构成组合逻辑电路对译码出来的二进制信号进行逻辑运算
 *
 * 运算的结果会写到内存里存储
 *
 * 程序存储器+数据存储器+指令寄存器+指令译码器 放在内存了【通用的cpu如个人电脑】
 * 而单片机芯片则是独立的存储
 *
 * 寄存器组负责与ALU逻辑运算单元进行通信，寄存器的上指令【二进制信号作为ALU的输入端】
 * 最终由各个运算【如与，或，复合逻辑运算，非等电路来完成逻辑运算】
 *
 * 以上大概是CPU的一个原理
 */
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

     //变量内存对齐测试
     int k=0;
     char m='c';
     int n=2;
     printf("%d,%d,%d\n", sizeof(k), sizeof(m), sizeof(n));
     printf("%#X,%#X,%#X\n",&k,&m,&n);
    return 0;
}