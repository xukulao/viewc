//
// Created by Administrator on 2011/4/1.
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
