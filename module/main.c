//
// Created by Administrator on 2019/4/30.
//
/**
 * 变量，函数等全是地址助记符号
 * 在链接时，连接器会根据符号找到地址进行重定位
 * ELF文件里存储了所有模块合并后的符号表 段位是.symtab
 * 程序在运行之前就确认好符号的地址：静态链接
 * 程序在运行时才确认符号的地址：动态链接
 *
 * 目标共享文件xx.so可与可执行文件连接，作为可执行程序的一部分运行，为动态链接库
 *
 *
 * 链接（Linking）就是通过符号将各个模块组合成一个独立的程序的过程。
 * 找到符号的地址，或者把指令中使用到的地址加以修正。这个过程称为符号决议（Symbol Resolution）或者重定位（Relocation）。
 *
 * 这种在程序运行之前确定符号地址的过程叫做静态链接（Static Linking）；如果需要等到程序运行期间再确定符号地址，就叫做动态链接（Dynamic Linking）。
 *
 * 地址修正的过程就是重定位，每个需要被修正的地方叫做一个重定位入口（Relocation Entry）。重定位所做的工作就是给程序中每个这样的绝对地址引用的位置“打补丁”，使它们指向正确的地址
 *
 *函数和变量在本质上是一样的，都是地址的助记符，在链接过程中，它们被称为符号（Symbol）。链接器的一个重要任务就是找到符号的地址，并对每个重定位入口进行修正。
 *
 * Strong Symbol 强符号  函数和全局初始化的变量有确定的值
 * Weak Symbol 弱符号  未初始化的全局变量
 *
 * 链接器对符号的处理：
 * 1、禁止多处定义强符号
 * 2、多处定义相同的强弱符号就用最强的
 * 3、多处定义相同的弱符号，就有占用空间最大的符号
 *  *  * */
#include <stdio.h>
extern void test();
extern int k;
//int b=10;
int b;//file.c也定义了，但已经有初始值为强符号  而此变量为弱符号  链接器会使用强符号的地址
__attribute__((weak)) int b=1000;//file.c也定义了它，并且为强符号，在这里虽然定义了但为弱符号
__attribute__((weak)) void test(){
    printf("k=%d\n",k);
}//弱符号函数

__attribute__((weak)) int c=1000;//为弱符号  但其它文件【模块】并没有定义 没有定义就用弱符号


__attribute__((weak)) extern int p1;//弱符号  弱引用
__attribute__((weak)) extern void func();
int main()
{
    c = 1000;
    printf("k in main %d\n",k);
    test();
    printf("b=%d\n",b);
    printf("c=%d\n",c);

    printf("******************************\n");
    int m1=10;  //符号定义
    int m2 = 100;//符号定义
    int m3;//符号定义
    m3 = m1+m2;//符号引用

    printf("m3=%d\n",m3);//符号引用  链接器会找到该符号的地址

    //printf("m4=%d\n",m4);//链接器找不到该符号的地址，就会报错  为强引用  对应的有弱引用，符号定义就引用它的地址，不定义也不报错
    //printf("p1=%#X,func100=%#X\n",&p1,func100);
    if (&p1){
        printf("p1=%d\n",p1);
    }else{
       // printf("p1 is undefined!\n");
 printf("p1 is undefined %d!\n",errno);
    }

//    if(func){
//        printf("func100\n",func());
//    }else{
//        printf("func100 is undefined!\n");
//    }
    return 0;
}
