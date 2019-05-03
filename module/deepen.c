//
// Created by 1655664358@qq.com on 2019/5/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct _STUS
{
    int id;
    char name[10];
    int age;
    int num;
}STU;

long copy(FILE *sourceFile,long offset,long len,FILE *targetFile,long targetSet);
int main()
{
    STU student1;
    student1.id = 100;
    char *name = "tony";
    student1.name[0] = 't';
    student1.age = 18;
    student1.num = 1;

//    //printf("%d\n",student1.id);
//    char *fileName = "E:/c/viewc/module/deepen.txt";
//    FILE *file = fopen(fileName,"wb+");
//    if (file!=NULL){
//        int i;
//        for(i=0;i<10;i++){
//            student1.id = i;
//            fwrite(&student1, sizeof(struct _STUS),1,file);
//        }
//    }
//
//    fclose(file);

    typedef struct _STU{
        int id;  //学号 4
        char name[20];  //姓名 20
        char sex[4];  //性别 4
        int age;  //年龄 4
        float math;  //数学成绩 4
        float cn;  //语文成绩 4
        float en;  //英语成绩 4
    }STU;

    int a = 5*44;
    int b = 1024*4;
    int n = ceil((double)((double)a/b));
    printf("a/b=%d\n",n);
    //printf("stu=%d,float=%d\n", sizeof(struct _STU), sizeof(int));
    return 0;
}

long copy(FILE *sourceFile,long offset,long len,FILE *targetFile,long targetSet)
{
    int bufferLen = 1024*4;
    char *buffer = (char *)calloc(bufferLen, sizeof(char));
    fseek(sourceFile,offset,SEEK_SET);
    fseek(targetFile,targetSet,SEEK_SET);
    long nBytes=0;
    int readCount=0;
    if (len<0){
        while((readCount=fread(buffer,bufferLen,1,sourceFile))>0){
            fwrite(buffer,bufferLen,1,targetFile);
            nBytes+=readCount;
        }
    }else{
        int n;

    }
}