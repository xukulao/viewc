//
// Created by 1655664358@qq.com on 2019/5/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stu.h"
int printfMainMenu();
int main()
{
    int MenuId;
    //init();
    while (1){
       // MenuId = printfMainMenu();
    }
    return 0;
}

int printfMainMenu()
{
    int MenuId;
    system("cls");
    printf("*******************weclome to use student management system(there are %d students)********************\n");
    printf("******************************************************************************************************\n");
    fflush(stdin);
    MenuId = getch();
    return MenuId;
}