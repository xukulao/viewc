//
// Created by Administrator on 2019/4/18.
//

#include <stdio.h>

int main()
{
    int a,b,sum;
    fprintf(stdout,"please enter some data!\n");
    fscanf(stdin,"%d %d",&a,&b);

    fprintf(stdout,"%d+%d=%d\n",a,b,a+b);
    return 0;
}