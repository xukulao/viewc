//
// Created by Administrator on 2013/4/18.

#include <stdio.h>

int main()
{

    FILE *file;
    char *Filename = "E:/c/demo/hello1.txt";
    file = fopen(Filename,"wt+");
    if (file == NULL){
        printf("not found file!");
    }
    char ch;
    while((ch=getchar())!='\n'){
        fputc(ch,file);
    }

    fclose(file)

    printf("write it ok!");
    return 0;
}
