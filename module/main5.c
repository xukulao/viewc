//
// Created by 1655664358@qq.com on 2019/5/1.
//
#include <stdio.h>
#include <stdlib.h>
int *age(int * ,int *);
char *city();
int sum()
{
    static int n=0;
    /**
     * 变量  地址的助记符号
     * 类型  静态int
     * 内容 0
     * 存储类别  static
     * 内存模型  全局数据区
     * 存储周期 整个程序周期有效
     * 变量地址  0X407030
     *
     * 链接器会根据该符号找到内存地址组合成一个可执行程序
     */
    n++;
    printf("n=%d\n",n);
    printf("n of address %#X\n",&n);
    return n;
}

int *age(int *a,int *b)
{
   int *c;
   int c1;
   c = &c1;
   *c=*a+*b;
   return c;
}

char *address()
{
    char *address="china";
    /**
     * address的内容是 beijing字符串的地址
     */
    return address;
}

char *city()
{
    char *citys[] = {
            "shanghai",
            "beijing",
            "guiyang"
    };
    /**
     * 数组，每个元素均为指针
     */
    //citys=&citys[0] citys[0]=&citys[0][0]
    return *citys;
}
int main()
{
    int i;
//    for(i=0;i<100;i++){
//        sum();
//    }
//    printf("****************************\n");
//    printf("n=%d\n",*(int *)(0X407030));
//
//    int (*func)() = sum;
//    func();
    //printf("c=%d\n",*age(1,1));

    //int *(*ageN)(int,int) = age;
    //x(int x,int y)
    //printf("c1=%#X\n",*ageN(100,200));
    //int *result = *age(10,20);
    //printf("age=%d\n",*result);
    //printf("age=%d\n",*age(199,2));
    //printf("age=%d\n",*age(100,200));
//    int *a;
//    int *b;
//    int a1=10;
//    int b1=20;
//    a=&a1;
//    b=&b1;
//    *b=100;
//    //printf("age=%d",age(a,b));
//    printf("a=%#X,a=%d,b=%#X,b=%d\n",a,*a,b,b1);

    int a1=10;
    int b1=10;
    int *a,*b;
    a=&a1;
    b=&b1;
    printf("age=%d\n",*age(a,b));
    a1=100;
    b1=200;
    printf("age=%d\n",*age(a,b));

    int *(*ageNum)(int *,int *) = age;
    a1=1000;
    b1=2000;
    printf("ageNum=%d\n",*ageNum(a,b));
    a1=20;b1=20;
    printf("ageNum=%d\n",*&*ageNum(a,b));

    printf("********************************\n");
    printf("address=%s\n",address());

    char *(*add)() = address;
    char *(*adds[2])() = {
            address,
            address
    };
    /**
     * adds[2]
     * char *()
     */
    printf("Add=%s\n",add());
    printf("Adds=%s\n",adds[0]());

    printf("****************************\n");
    printf("city=%s\n",city());
    printf("city=%s\n",city()+1);

    char *(*cityss[2])()={
            city,
            city
    };
    printf("cityss=%s\n",cityss[0]());


    printf("********************\n");
//    int *bb;
//    *bb=10;//报错
//    printf("bb=%d\n",*bb);
    int *bb;
    bb = (int *)malloc(10* sizeof(int));
    *bb=10;
    printf("bb=%d\n",*bb);
    free(bb);

    int *cc[2];
    cc[0] = (int *)calloc(2, sizeof(int));
    *cc[0] = 1;
    printf("cc[0]=%d\n",*cc[0]);
    return 0;
}
