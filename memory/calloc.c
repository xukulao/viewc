//
// Created by Administrator on 2019/4/26.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    int *Data;

    printf("enter size:\n");
    scanf("%d",&i);
    Data = (int *) calloc(i, sizeof(int));//分配i个，每个大小为int即4个字节 i*4个字节
    if (Data==NULL)exit(0);

    for(n=0;n<i;n++){
        printf("enter the num %d\n",n+1);
       // scanf("%d",&Data[n]);
       scanf("%d",Data+n);
    }

    printf("your input is:\n");
    for(n=0;n<i;n++){
        printf("Data[%d]=%d\n",n,*(Data+n));
    }

    free(Data);

    return 0;
}
