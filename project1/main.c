//
// Created by 1655664358@qq.com on 2019/5/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stu.h"

char printfMainMenu();
int main()
{
    int MenuId;
    init();
    while (1){
       MenuId = printfMainMenu();
       switch (MenuId){
           case '1':
                addStu();break;
           case '2':break;
           case '3':break;
           case '4':break;
           case '5':break;
           case '0':exit(EXIT_SUCCESS);
       }
    }
    return 0;
}

char printfMainMenu()
{
    char MenuId;
    system("cls");
    printf("*******************weclome to use student management system(there are %d students)*******************\n");
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