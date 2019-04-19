//
// Created by Administrator on 2019/4/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long fcopy(FILE *sourceFile,long offsetCource,long len,FILE *targetFile,long offsetTarget);
int finsert(FILE *file,long offset,void *buffer,int len);
int fdelete(FILE *file,long offset,int len);

int main()
{

    char *fileName = "E:/c/demo/hello10.txt";
    char *targetFileName = "E:/c/demo/hello100.txt";

    FILE *file = fopen(fileName,"rb");
    int bufferLen = 1024*4;
    char *buffer = (char *)malloc(bufferLen);



    //int readcount = fread(buffer,1,bufferLen,file);
    //int readcount = fread(buffer,1,512,file);
    //int readcount = fread(buffer,1024,4,file);
    //int readcount = fread(buffer,1024,4,file);
    //int readcount = fread(buffer,1,4,file);
//    int readcount = fread(buffer,7,1,file);


    fseek(file,2,SEEK_SET);

    printf("pos=%d\n",ftell(file));
    int readcount = fread(buffer,1,5,file);

    printf("pos=%d\n",ftell(file));
    printf("%s %d\n",buffer,readcount);


    FILE *targetFile = fopen(targetFileName,"wb");
    //fwrite(buffer,1,bufferLen,targetFile);
    //fwrite(buffer,readcount,1,targetFile);
    //fwrite(buffer,11,1,targetFile);
    //fwrite(buffer,1,1024,targetFile);
    //fwrite(buffer,5,2,targetFile);
    //fwrite(buffer,5,3,targetFile);
    fwrite(buffer,readcount,1,targetFile);

    fclose(targetFile);
    fclose(file);

    free(buffer);
    return 0;
}

long fcopy(FILE *sourceFile,long offsetCource,long len,FILE *targetFile,long offsetTarget)
{
    int bufferLen = 1024*4;

    char *buffer = (char *)malloc(bufferLen);

    int readCount;
    long nBtypes = 0;

    int n;
    int i;
    fseek(sourceFile,offsetCource,SEEK_SET);
    fseek(targetFile,offsetTarget,SEEK_SET);

    if (len<0){
        //一次读取一个字节，一个字节，每个字节4kb
        while(readCount=fread(buffer,1,bufferLen,sourceFile)>0){
            nBtypes+readCount;

            fwrite(buffer,readCount,1,targetFile);
        }
    }else{
        n = (int)ceil((double)((double)len/bufferLen));
        for(i=1;i<=n;n++){
            if(len-nBtypes<bufferLen){bufferLen=len-nBtypes;}

            readCount = fread(buffer,1,bufferLen,sourceFile);
            fwrite(buffer,readCount,1,targetFile);
            nBtypes+=readCount;

        }
    }

    fflush(targetFile);
    free(buffer);
    return nBtypes;
}
