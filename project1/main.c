//
// Created by 1655664358@qq.com on 2018/5/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "common.h"
#include "stu.h"
/**
 *
 * 文件的复制
 * 内存复制
 * readByte=fread(buffer,1,size,file)从文件复制1个大小为size的内容
 *
 * fwrite(buffer,size=readByte,1,file)  将1个大小size=readCount的内容插入到文件中
 */


char printfMainMenu();
char printfChildMenu();
int main()
{
    int MenuId;
    init();
    while (1){
       MenuId = printfMainMenu();
       switch (MenuId){
           case '1':addStu();break;
           case '2':removeStu();break;
           case '3':alterStu();break;
           case '4':
                while (1){
                    MenuId = printfChildMenu();
                    switch(MenuId){
                        case '1':
                            findStuById();
                            break;
                        case '2':
                            findStuByName();
                            break;
                        case '3':
                            findByScores(FIND_BY_MATH);
                            break;
                        case '4':
                            findByScores(FIND_BY_ZH);
                            break;
                        case '5':
                            findByScores(FIND_BY_EN);
                            break;
                        case '6':
                            findByScores(FIND_BY_TOTAL);
                            break;
                    }
                    if (MenuId=='0')break;
                }
               break;
           case '5':showAllStu();break;
           case '0':exit(EXIT_SUCCESS);
       }
    }
    return 0;
}

char printfMainMenu()
{
    char MenuId;
    system("cls");
    printf("*******************weclome to use student management system(there are %d students)*******************\n",stuCount);
    printf("*                                                                                                         *\n");
    printf("*                   ________________________________________                                              *\n");
    printf("*                   |    powered by 1655664358@qq.com      |                                              *\n");
    printf("*                   ----------------------------------------                                              *\n");
    printf("*                                                                                                         *\n");
    printf("*                   1)添加学生                                                                               \n");
    printf("*                   2)删除学生信息(根据学号)                                                                   \n");
    printf("*                   3)修改学生信息(根据学号)                                                                   \n");
    printf("*                   4)查询学生信息                                                                           \n");
    printf("*                   5)学生列表                                                                               \n");
    printf("*                   0)退出软件                                                                              \n");
    printf("*                                                                                                         \n");
    printf("***********************************************************************************************************\n");
    fflush(stdin);
    MenuId = getch();
    return MenuId;
}

char printfChildMenu()
{
    char menuId;
    system("cls");
    printf("*********************************************查询信息(共有%d个学生)************************************************\n",stuCount);
    printf("*                                                                                                              *\n");
    printf("*                                            1)学号查                                                           *\n");
    printf("*                                            2)姓名查                                                           *\n");
    printf("*                                            3)数学分数查                                                           *\n");
    printf("*                                            4)语文分数查                                                           *\n");
    printf("*                                            5)英文分数查                                                           *\n");
    printf("*                                            6)总分查                                                           *\n");
    printf("*                                            0)退出                                                           *\n");
    fflush(stdin);
    menuId = getch();
    return menuId;
}
