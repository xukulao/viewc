//
// Created by Administrator on 2019/4/20.
//

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