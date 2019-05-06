//
// Created by 1655664358@qq.com on 2019/5/6.
//
#include <stdio.h>
#include "stu.h"
#include "tool.h"
#include <conio.h>
#include <stdlib.h>
void init()
{
    if ((file=fopen(FILENAME,"wb+"))==NULL&&(file=fopen(FILENAME,"rb+"))==NULL){
        pause("Error on open %s file",FILENAME);
        exit(EXIT_FAILURE);
    }

    fileSize = getFileSize(file);
    stuCount = fileSize/stuSize;
    stuIndex = NULL;
    updateIndex();
}

void updateIndex()
{
    stuIndex = (int *)malloc(stuCount*stuSize);
    int i;
    for(i=0;i<stuCount;i++){
        fseek(file,i*stuSize,SEEK_SET);
        fread(&stuIndex[i], sizeof(int),1,file);
    }
}