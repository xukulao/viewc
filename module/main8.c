//
// Created by 1655664358@qq.com on 2019/5/4.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
long getFileSize(FILE *file);
long fcopy(FILE *sourceFile,long offset,long len,FILE *targetFile,long targetOffset);
void writeFile(FILE *file);
void copyTest();
typedef struct _PERSON
{
    char name[20];
    int age;
    int num;
    char address[50];
}PERSON;
char *fileName = "E:/c/demo/module/main8.txt";
FILE *file;
int main()
{
    if((file=fopen(fileName,"wb+"))!=NULL){
        writeFile(file);
    }
    return 0;
}


void copyTest()
{

}

void writeFile(FILE *file)
{
    PERSON jack;
    jack.name[0] = 'j';
    jack.age = 100;
    jack.num = 101;
    jack.address[0] = 'b';

    int personSize = sizeof(struct _PERSON);

    fwrite(&jack,personSize,1,file);

    PERSON tony;
    tony.name[0] = 't';
    tony.age = 100;
    tony.num = 101;
    tony.address[0] = 's';
    fwrite(&tony,personSize,1,file);
    PERSON lucy;
    lucy.name[0] = 'l';
    lucy.age = 100;
    lucy.num = 101;
    lucy.address[0] = 't';
    fwrite(&lucy,personSize,1,file);
    fclose(file);
}
long getFileSize(FILE *file)
{
    long fsize;
    fpos_t fpos;
    fgetpos(file,&fpos);
    fsize = fseek(file,0,SEEK_END);
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
    if (len<0){
        while((readCount=fread(buffer,1,bufferLen,sourceFile))>0){
            fwrite(buffer,bufferLen,1,targetFile);
            nBtyte+=readCount;
        }
    }else{
        n = (int)ceil((double)((double)len/bufferLen));
        for(i=1;i<=n;i++){
            if (len-nBtyte<bufferLen)bufferLen=len-nBtyte;
            readCount = fread(buffer,1,bufferLen,sourceFile);
            fwrite(buffer,bufferLen,1,targetFile);
            nBtyte+=readCount;
        }
    }
    fflush(targetFile);
    free(buffer);
    return nBtyte;

}

