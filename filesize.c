//
// Created by Administrator on 2016/4/19.
//

#include <stdio.h>

long filesize(FILE *file);

int main()
{

    char *fileName = "E:/c/demo/hello.txt";
    FILE *file = fopen(fileName,"rb");
    if (file == NULL){
        printf("file not found!");
    }

    printf("file size =%ld bytes!\n",filesize(file));
    return 1;
}

long filesize(FILE *file)
{
    long n;
    fpos_t f_pos;
    fgetpos(file,&f_pos);//得到文件的当前指针位置

    fseek(file,0,SEEK_END);

    n = ftell(file);

    fsetpos(file,&f_pos);//重置回原来的位置

    return n;
    2
}
