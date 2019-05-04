//
// Created by 1655664358@qq.com on 2019/5/4.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
long getFileSize(FILE *file);
long fcopy(FILE *sourceFile,long offset,long len,FILE *targetFile,long targetOffset);
void writeFile(FILE *file);
void copyTest();
void readFile();
typedef struct _PERSON
{
    char name[20];
    int age;
    int num;
    char address[50];
}PERSON;
char *fileName = "E:/c/demo/module/main8.txt";
char *copyFileName = "E:/c/demo/module/copymain8.txt";

FILE *file;
FILE *copyfile;
int personSize = sizeof(struct _PERSON);
int main()
{
//    if((file=fopen(fileName,"rb+"))!=NULL){
//       writeFile(file);
//    }

    copyTest();
    return 0;
}


void copyTest()
{
//    if((file=fopen(fileName,"rb+"))==NULL){
//        exit(0);
//    }
//    if ((copyfile=fopen(copyFileName,"rb+"))==NULL){
//        exit(0);
//    }


    //第一步复制全部
//    long nBytes=0;
////    nBytes = fcopy(file,0,-1,copyfile,0);
////    printf("copy %d bytes\n",nBytes);
//
//    //第二步复制一部分 目标文件从0开始插入  这是复制前半部分
//    long startOffset = 1*personSize;
//
//    nBytes = fcopy(file,0,startOffset,copyfile,0);
//    printf("copy %d bytes\n",nBytes);

    //第三步复制后半部分
//    long startOffset = 2*personSize;
//    long
//

//    PERSON person;
//    scanf("%s",person.name);
//    scanf("%d",&person.age);
//    scanf("%d",&person.num);
//    scanf("%s",person.address);
//
//    //往复制的文件上写入一个数据
//    copyfile=fopen(copyFileName,"rb+");
//    long fsize = getFileSize(copyfile);
//    printf("fsize=%d\n",fsize);
//    fseek(copyfile,fsize,SEEK_SET);//往后面写，免得擦掉前面写的东西了
//    fwrite(&person,personSize,1,copyfile);
//fclose(copyfile);
    //复制后半部分
//    long startOffset = 1*personSize;
//    long nBytes=0;
//    nBytes = fcopy(file,startOffset,-1,copyfile,startOffset+personSize);
//    printf("last copy %d bytes\n",nBytes);

    //复制全部到原文件
//    file = fopen(fileName,"wb+");
//    copyfile = fopen(copyFileName,"rb+");
//    long nBytes;
//    nBytes = fcopy(copyfile,0,-1,file,0);
//    printf("copy %d bytes\n",nBytes);

    readFile();
}

void readFile()
{
    file = fopen(fileName,"rb+");

    int readCount=0;
    PERSON person;
    int personNum = getFileSize(file)/personSize;

    char *index[personNum];

    int k=0;
    for(k;k<personNum;k++){
        index[k] = (char *)malloc(20* sizeof(char));
        fseek(file,k*personSize,SEEK_SET);
        fread(index[k], sizeof(char),20,file);
        printf("%s\n",index[k]);
    }

//    fseek(file,0,SEEK_END);
//    while((readCount=fread(&person,personSize,1,file))>0){
//
////        if (!person.name[0]){
////            break;
////        }
//        printf("person.name[0]=%s\n",person.name);
//    }
}

void writeFile(FILE *file)
{
//    PERSON jack;
//    jack.name[0] = 'j';
//    jack.age = 100;
//    jack.num = 101;
//    jack.address[0] = 'b';
//
//
//
//    fwrite(&jack,personSize,1,file);
//
//    PERSON tony;
//    tony.name[0] = 't';
//    tony.age = 100;
//    tony.num = 101;
//    tony.address[0] = 's';
//    fwrite(&tony,personSize,1,file);
//    PERSON lucy;
//    lucy.name[0] = 'l';
//    lucy.age = 100;
//    lucy.num = 101;
//    lucy.address[0] = 't';
//    fwrite(&lucy,personSize,1,file);
    PERSON person;
    int i=0;
    for(i;i<2;i++){

        scanf("%s",person.name);
        scanf("%d",&person.age);
        scanf("%d",&person.num);
        scanf("%s",person.address);
        fseek(file,getFileSize(file),SEEK_SET);
        fwrite(&person,personSize,1,file);

    }
    fclose(file);
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

long fcopy(FILE *sourceFile,long offset,long len,FILE *targetFile,long targetOffset)
{
    int bufferLen = 1024*4;
    char *buffer = (char *)malloc(bufferLen);


    fseek(sourceFile,offset,SEEK_SET);
    fseek(targetFile,targetOffset,SEEK_SET);


    long nBtyte=0;
    int readCount=0;
    int i,n;

    /*****复制调整*****/
    PERSON person;

    if (len<0){
        while( (readCount=fread(&person,personSize,1,sourceFile)) >0 ){
            if (person.name[0]){
                fwrite(&person,personSize,1,targetFile);
                nBtyte+=readCount;
            }

        }
    }else{
//        n = (int)ceil((double)((double)len/bufferLen));
//        for(i=1;i<=n;i++){
//            if (len-nBtyte<bufferLen)bufferLen=len-nBtyte;
//            readCount = fread(buffer,1,bufferLen,sourceFile);
//            fwrite(buffer,bufferLen,1,targetFile);
//            nBtyte+=readCount;
//        }

        n = len/personSize;
        for(i=1;i<=n;i++){
            readCount = fread(&person,personSize,1,sourceFile);
            fwrite(&person,personSize,1,targetFile);
            nBtyte+=readCount;
        }
    }
    fflush(targetFile);
    free(buffer);
    return nBtyte;

}

