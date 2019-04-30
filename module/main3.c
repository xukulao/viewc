//
// Created by Administrator on 2019/4/30.
//
#include <stdio.h>
int m = 100;
struct person
{
    char name[20];
    int age;
    int num;
};

struct person tony[2]={
        {"tony",20,100},
        {"jack",30,120}
};
extern void show();
void showM();

int func()
{
    static int n=0;//这里的语句是没有用的，static修饰的变量具有持久化的作用，只执行一次
    //只能修改它的值，不能初始化多次
    n++;
    printf("function is caleed %d times\n",n);
    return 0;
}

/**
 * static 可以隔离模块  使变量函数限制在某个模块的作用域下【类似oop里的私有成员】
 * static 修饰局部变量具有持久化的功能【保存在全局数据区了】并且只能初始化一次
 * @return
 */
int main(void)
{
//    showM();
//    tony[0].age = 10;
//    printf("age=%d\n",tony[0].age);
//
//    show();
    int i,n=0;
    for(i=0;i<5;i++){
        func();
    }
    printf("n=%d\n",n);

   return 0;
}
void showM()
{
    printf("m=%d\n",m);
}