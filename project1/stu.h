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
extern void removeStu();
extern void alterStu();
extern void getStuId(int *id);
extern int checkStuId(int stdId);
extern void getStuName(char name[]);
extern int checkStuName(char name[]);
extern void getStuAge(int *age);
extern void getStuSex(char sex[]);
extern void getStuMath(float *math);
extern void getStuZh(float *zh);
extern void getStuEn(float *en);
extern int checkStuAge(int age);
extern int checkStuSex(char sex[]);
extern int checkStuMath(float math);
extern int checkStuZh(float zh);
extern int checkStuEn(float en);
extern void showAllStu();
#endif //STUDENT_TOOL_H
