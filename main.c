//
// Created by Administrator on 2019/4/15.
//

#include <stdio.h>
int main(int argc,char *argv[])
{
    printf("there are %d params\n",argc);
    int i=0;
    for(i=0;i<argc;i++){
        printf("argv[%d]=%s\n",i,*(argv+i));
    }
    getchar();
}