//
// Created by 1655664358@qq.com on 2019/5/6.
//

#ifndef _STU_H
#define _STU_H

#include "common.h"
typedef struct _STU
{
    int id;
    char name[20];
    int age;
    char sex[4];
    float math;
    float zh;
    float en;
}STU;

int stuSize = sizeof(struct _STU);
int stuCount = 0;
FILE *file;
long fileSize=0;
int *stuIndex;
void init();
void updateIndex();


#endif //STUDENT_TOOL_H
