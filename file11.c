//
// Created by Administrator on 2019/4/1.
//
/**
 * 文件复制和读取
 */
#include <stdio.h>
#include <stdlib.h>
int copyFile(char *readFile,char *writeFile);
int main()
{
    char readFile[200];
    char writeFile[200];
    printf("please enter readFile name:\n");
    scanf("%s",readFile);
    printf("please enter writeFile name:\n");
    scanf("%s",writeFile);

    if (copyFile(readFile,writeFile)){
        printf("copy file success!\n");

        FILE *file = fopen(readFile,"rb");
       char *buffer = (char*)malloc(1024*4);
        if (file != NULL){
            while(fread(buffer,1,1024*4,file)>0){
                fprintf(stdout,"%s",buffer);
            }

        }else{
            printf("file not exits!");
        }
        free(buffer);
        fclose(file);
    }else{
        printf("copy file error!");
    }
    return 0;
}

int copyFile(char *readFile,char *writeFile)
{
    FILE *readFileFp;
    FILE *writeFileFP;

    readFileFp = fopen(readFile,"rb");
    writeFileFP = fopen(writeFile,"wb");
    if(readFileFp == NULL || writeFileFP == NULL){
        printf("readfile or writefile not exists!");
    }

    int bufferLen = 1024*4;
    int readCount;
    char *buffer = (char*)malloc(bufferLen);

    while(readCount=fread(buffer,1,bufferLen,readFileFp)>0){
        fwrite(buffer,1,bufferLen,writeFileFP);
    }

    free(buffer);
    fclose(readFileFp);
    fclose(writeFileFP);
    return 1;
}
