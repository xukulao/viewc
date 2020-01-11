//
// Created by Administrator on 2016/4/1
//

#include <stdio.h>
#include <string.h>
int main()
{
    FILE *file;
    char *fileName = "E:/c/demo/hello.txt";
    file = fopen(fileName,"at+");
    if (file == NULL){
        printf("not found file!");
    }

    printf("input your data!\n");
    char str[102]= {0};
    char tempStr[100];
    gets(tempStr);
    strcat(str,"\n");
    strcat(str,tempStr);

    printf("str=%s\n",str);
    if(fputs(str,file)==EOF){
        printf("write error!");
    }else{
        printf("write ok!");
    }
    printf("end");
    fclose(file);
    return 0;

}
