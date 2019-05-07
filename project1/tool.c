//
// Created by 1655664358@qq.com on 2019/5/6.
//
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "tool.h"



int finsert(FILE *file,long offset,void *buffer,int len)
{
    long fileSize = getFileSize(file);
    FILE *tmpFile = tmpfile();
    if (offset>fileSize||offset<0||len<0){
        return -1;
    }else if(offset==fileSize){
        fseek(file,offset,SEEK_SET);
        if(!fwrite(buffer,len,1,file)){
            return -1;
        }
    }else if(offset<fileSize){
        //插入到文件中间或前面
        fcopy(file,0,offset,tmpFile,0);
        fseek(tmpFile,offset,SEEK_SET);
        fwrite(buffer,len,1,tmpFile);
        fcopy(file,offset,-1,tmpFile,offset+len);
        freopen(FILENAME,"wb+",file);
        fcopy(tmpFile,0,-1,file,0);
        fclose(tmpFile);
    }
    return 0;
}

int fdelete(FILE *file,long offset,long len)
{
    long fileSize = getFileSize(file);
    FILE *tmpFile = tmpfile();
    if (offset<0||len<0||offset>fileSize){
        return -1;
    }else{
        fcopy(file,0,offset,tmpFile,0);
        fcopy(file,offset+len,-1,tmpFile,offset);
        freopen(FILENAME,"wb+",file);
        fcopy(tmpFile,0,-1,file,0);
        fclose(tmpFile);
    }

    return 0;


}

long fcopy(FILE *sourceFile,long sourceOffset,long len,FILE *targetFile,long targetOffset)
{
    int i,n;
    long nByte=0;
    int bufferLen = 1024*4;
    char *buffer = (char *)malloc(bufferLen);//动态分配4k内存
    int readCount=0;
    fseek(sourceFile,sourceOffset,SEEK_SET);//从什么地方
    fseek(targetFile,targetOffset,SEEK_SET);

    if (len<0){
        //复制全部
        while((readCount=fread(buffer,1,bufferLen,sourceFile))>0){
            fwrite(buffer,readCount,1,targetFile);
            nByte+=readCount;
        }
    }else{
        n = (int)ceil((double)((double)len/bufferLen));//整数相除值可能为浮点数  故先转换
        for(i=1;i<=n;i++){
            if (len-nByte<bufferLen)bufferLen=len-nByte;//bufferLen=1 len=10 nByte=1 len=9 10
            readCount = fread(buffer,1,bufferLen,sourceFile);
            fwrite(buffer,readCount,1,targetFile);
            nByte+=readCount;
        }
    }
    fflush(targetFile);
    free(buffer);
    return nByte;
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
void pause(const char *str,...)
{
    va_list ap;
    char buffer[50];
    va_start(ap,str);
    vsnprintf(buffer,500,str,ap);
    va_end(ap);
    printf(buffer);
    getch();
    printf("\n");
}
