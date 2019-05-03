//
// Created by 1655664358@qq.com on 2019/5/3.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *file;
int main()
{
    char *fileName = "E:/c/viewc/module/file100.txt";
    file = fopen(fileName,"wb+");
    //char *content = (char *)malloc(10);
    char *content;
    content = "china";
    if (file!=NULL){
        fwrite(content, sizeof(char),strlen(content),file);
    }
    fclose(file);

    FILE *readFile;
    readFile = fopen(fileName,"rb+");
    char *readContent =(char *)calloc(5, sizeof(char));
    if (readFile!=NULL){
        fread(readContent, sizeof(char), 5,readFile);
    }
    printf("readContent=%s\n",readContent);
    fclose(readFile);

    return 0;
}

