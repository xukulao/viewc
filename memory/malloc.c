//
// Created by Administrator on 2019/4/26.
//

#include <stdio.h>
#include <stdlib.h>
//动态分配内存  分配的内存位于堆区
int main()
{
    int n,i;
    char *buffer;

    printf("enter buffer size:\n");
    scanf("%d",&i);
    buffer = (char *)malloc(i+1);//申请内存
    printf("%d\n", sizeof(buffer));
    if (buffer == NULL)exit(0);
    for(n=0;n<i;n++){
        buffer[n] = rand()%26+'a';
    }
    buffer[i]='\0';

    printf("buffer is %s\n",buffer);
    free(buffer);//释放内存
    return 0;
}