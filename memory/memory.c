//
// Created by Administrator on 2019/4/25.
//
#include <stdio.h>
int a = 100;//全局变量  位于全局数据区
char *str1 = "phpisbestlanguage";//字符串常量位于常量区 str1位于全局数据区

char *test()
{
    char *hi = "hello,world";//函数内的变量都位于栈区  常量字符串位于常量区
    return hi;
}
char test1()
{
    char *h = "clanguage";//常量字符位于常量区  不会失效，函数进栈和出栈不会影响它
    printf("h=%#X\n",h);

    int k = 100;//位于栈区  会失效，函数出栈【释放】会失效
    printf("k=%d,k=%#X\n",k,&k);
}
int main(){

    int m=10;//位于栈区
    char *hi = test();//位于栈区
    char *name = "php";//字符串位于常量 区  name位于栈区
    char address[1] = "china";//全部位于栈区

    printf("a=%#X\n",&a);
    printf("str1=%#X\n",str1);
    printf("&str1=%#X\n",&str1);


    printf("m=%#X\n",&m);
    printf("hi=%#X\n",hi);
    printf("name=%#X\n",name);
    printf("address=%#X\n",address);

    test1();
    char *h=(char *)0X40404E;
    printf("h=%s\n",h);

    int *k=(int *)0X62FDC4;
    printf("k=%d\n",*k);

    return 0;
}