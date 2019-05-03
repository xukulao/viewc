//
// Created by 1655664358@qq.com on 2019/5/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
typedef struct _STUS
{
    int id;
    char name[10];
    int age;
    int num;
}STU;
long getFileSize(FILE *file);
long copy(FILE *sourceFile,long offset,long len,FILE *targetFile,long targetSet);
int main()
{
    STU student1;
    student1.id = 100;
    char *name = "tony";
    student1.name[0] = 't';
    student1.age = 18;
    student1.num = 1;

    char *fileName = "E:/c/viewc/module/deepen.txt";
    FILE *file = fopen(fileName,"wb+");
    if (file!=NULL){
        int i;
        for(i=0;i<10;i++){
            student1.id = i;
            fwrite(&student1, sizeof(struct _STUS),1,file);
        }
    }

    fclose(file);

/***********************************************************/
//    FILE *readFileHandle = fopen(fileName,"rb+");
//
//    FILE *tmpFile = tmpfile();
//
//    if (tmpFile==NULL){
//        printf("无法创建临时文件!\n");
//        exit(0);
//    }
//    copy(readFileHandle,0,5* sizeof(struct _STUS),tmpFile,0);
//
//    STU student2;
//    student2.id = 102;
//    student2.name[0] = 'k';
//    student2.age = 18;
//    student2.num = 1;
//
//    fwrite(&student2,sizeof(struct _STUS),1,tmpFile);
//    copy(readFileHandle,5* sizeof(struct _STUS),-1,tmpFile,5* sizeof(struct _STUS)+sizeof(struct _STUS));
//
//
//     freopen(fileName,"wb+",readFileHandle);
//    copy(tmpFile,0,-1,readFileHandle,0);
//
//    fclose(readFileHandle);
//    fclose(tmpFile);
//
//    getchar();

/***********************************************************/
//    typedef struct _STU{
//        int id;  //学号 4
//        char name[20];  //姓名 20
//        char sex[4];  //性别 4
//        int age;  //年龄 4
//        float math;  //数学成绩 4
//        float cn;  //语文成绩 4
//        float en;  //英语成绩 4
//    }STU;

    //int a = 5*44;
    //int b = 1024*4;
    //int n = ceil((double)((double)a/b));
    //printf("a/b=%d\n",n);
    //printf("stu=%d,float=%d\n", sizeof(struct _STU), sizeof(int));
    return 0;
}

long getFileSize(FILE *file)
{
    long fsize;
    fpos_t fpos;
    fgetpos(file,&fpos);
    fseek(file,0,SEEK_END);
    fsize = ftell(file);
    fsetpos(file,&fpos);
    return fsize;
}

long copy(FILE *sourceFile,long offset,long len,FILE *targetFile,long targetSet)
{
    int bufferLen = 1024*4;
    char *buffer = (char *)calloc(bufferLen, sizeof(char));
    fseek(sourceFile,offset,SEEK_SET);
    fseek(targetFile,targetSet,SEEK_SET);
    long nBytes=0;
    int readCount=0;

    int i,n;
    if (len<0){
        while((readCount=fread(buffer,bufferLen,1,sourceFile))>0){
            fwrite(buffer,bufferLen,1,targetFile);
            nBytes+=readCount;
        }
    }else{
        n = (int)ceil((double)((double)len/bufferLen));
        for(i=1;i<=n;i++){
            if(len-nBytes<bufferLen)bufferLen=len-nBytes;
            readCount = fread(buffer,bufferLen,1,sourceFile);
            fwrite(buffer,bufferLen,1,targetFile);
            nBytes+=readCount;
        }

    }
    fflush(targetFile);
    free(buffer);
    if (nBytes>0&&getFileSize(targetFile)>0){
        printf("copy success\n");
    }
    return nBytes;
}