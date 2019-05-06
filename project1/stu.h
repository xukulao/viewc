//
// Created by 1655664358@qq.com on 2019/5/6.
//

#ifndef _STU_H
#define _STU_H
int stuCount;
FILE *file;
long fileSize;
int *stuIndex;
int stuSize;
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

extern void init();
extern void updateIndex();
extern void addStu();
extern void getStuId(int *id);
extern int checkStuId(int stdId);
#endif //STUDENT_TOOL_H
