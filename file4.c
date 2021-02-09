//
// Created by Administrator on 2011/4/18.
//
#include <stdio.h>
#define LEN 100
int main()
{
    FILE *file;

    char *fileName = "E:/c/demo/hello.txt";
    file = fopen(fileName,"rt");
    if (file == NULL){
        printf("not found file!");
    }
    char c[LEN+1];
    while(fgets(c,LEN,file)!=NULL){
        puts(c);
    }

    fclose(file);
    return 0;
}
