//
// Created by Administrator on 2018/4/18.
//
// author 勺颠颠
#include <stdio.h>
typedef struct file
{
    char *name;
    int size;
    char *content;
}FILE_TEST;
int main()
{

    //FILE *file = fopen("hello.txt","rb");

//    struct file f = {"hello.txt",200,"hello,wrold"};
//
//    FILE_TEST *file_test = &f;
//    printf("f.name=%s\n",file_test->name);

    FILE *file=fopen("E:/c/demo/hello.txt","rb+");
    if(file == NULL){
        printf("Error,not found this file!");
        //getche();
        //exit(1);
    }
    fclose(file);

    return 0;
}
