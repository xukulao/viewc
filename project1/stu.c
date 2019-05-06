//
// Created by 1655664358@qq.com on 2019/5/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "common.h"
#include "stu.h"
#include "tool.h"
void init()
{
    if ((file=fopen(FILENAME,"wb+"))==NULL&&(file=fopen(FILENAME,"rb+"))==NULL){
        pause("Error on open %s file",FILENAME);
        exit(EXIT_FAILURE);
    }

    fileSize = getFileSize(file);
    stuSize = sizeof(STU);
    stuCount = fileSize/stuSize;
    stuIndex = NULL;
    updateIndex();
}

void updateIndex()
{
    free(stuIndex);
    stuIndex = (int *)malloc(stuCount*stuSize);
    int i;
    for(i=0;i<stuCount;i++){
        fseek(file,i*stuSize,SEEK_SET);
        fread(&stuIndex[i], sizeof(int),1,file);
    }
}

void addStu()
{
    STU stu;
    getStuId(&stu.id);
    printf("stu.id=%d\n",stu.id);
    pause("按任意键返回...");
}

void getStuId(int *id)
{
    while(1){
        printf("请输入ID\n");
        fflush(stdin);
        scanf("%d",id);
        if (checkStuId(*id)){
            break;
        }
    }
}

int checkStuId(int stdId)
{
    if(stdId<0||stdId>STU_MAX_ID){
        return 0;
    }else{
        return 1;
    }
}