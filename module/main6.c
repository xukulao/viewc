//
// Created by 1655664358@qq.com on 2019/5/3.
//

#include <stdio.h>
#include <stdlib.h>
int main()
{
//    int *pa;
//    int a=10;
//    pa=&a;
//    printf("pa=%d,pa=%#X,pa=%d\n",*pa,pa, sizeof(pa));
//
//    char b='c';
//    char *pb;
//    pb=&b;
//    printf("pb=%c,pb=%#X,pb=%d\n",*pb,pb, sizeof(pb));
//    pb="chinailoveu";
//    printf("pb=%s\n",pb);
//
//    printf("***********************\n");
//    char *pc;
//    pc="hello";
//    printf("pc=%s,pc=%d\n",pc, sizeof(pc));
//    printf("hello=%s,hello=%#X,hello=%d\n","hello","hello", sizeof("hello"));
//
//
//    printf("hello=%c\n","hello"[0]);
//    printf("hello=%c\n",*"hello"+0);
//    printf("hello=%c\n",*"hello");


//    char *pd = (char *)malloc(10);
//    printf("pd=%d,pd=%#X\n", sizeof(pd),pd);
//    pd = "china";
//    printf("pd=%s,pd=%#X\n",pd,pd);
//
//    pd = "japanese";
//    printf("pd=%s,pd=%#X\n",pd,pd);
    //pd动态分配的内存都没有使用

//    char *pd = (char *)malloc(10* sizeof(char));
//    pd[0] = 'c';
//
//    printf("pd=%c,pd=%#X\n",pd[0],pd);
//
//    scanf("%s",pd);
//    printf("pd=%s,pd=%#X\n",pd,pd);
//    free(pd);


    int *pe = (int *)calloc(2, sizeof(int));
    pe[0] = 1;
    pe[1] = 3;
    pe[2] = 3;
    printf("pe=%d\n",*pe+0);
    printf("pe=%d\n",*(pe+1));
    printf("pe=%d\n",*(pe+2));

    int pei;
    for(pei=0;pei<100;pei++){
        pe[pei] = pei;
    }
    printf("pe[80]=%d\n",pe[80]);
    pe[1024*1024] = 1024;
    printf("pe[1024=%d\n",pe[1024*1024]);
    return 0;
}