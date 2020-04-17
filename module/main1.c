//
// Created by Administrator on 2019/4/30.
//
/**
 * cpu
 * 内存映射
 * 内存页
 * MMU
 * 内存模型
 * 内存动态分配
 * 野指针和非法内存
 * 内存丢失
 * 存储类别和周期
 *
 * 链接
 * 静态链接
 * 动态链接
 * 符号
 * 符号类型
 * 强符号
 * 弱符号
 * 引用
 * 强引用
 * 弱引用
 * elf
 *  */
#include <stdio.h>
#include "module2.h"
FILE *file;
typedef struct person{
    char *name;
    int age;
    int num;
}person;
int main()
{
    talk();

    char fileName[100] = "E:/c/demo/module/person.txt";
    file = fopen(fileName,"rb+");
    person tony;
    tony.name = "tony";
    tony.age = 100;
    tony.num= 101;
    if (file != NULL){
        fwrite(&tony, sizeof(struct person),1,file);
         fwrite(&tony, sizeof(struct person),1,1);
    }
    //fclose(file);
    

    return 0;
}
