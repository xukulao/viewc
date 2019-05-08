//
// Created by 1655664358@qq.com on 2019/5/8.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void pause(char msg[]);
char showMenu();
void test();
int main()
{
    int id;
    while(1){
        id = showMenu();
        switch (id){
            case '1':
                test();
                break;
            case '2':
                printf("hello\n");
                pause("enter any key return ...");
                break;
            case '0':exit(EXIT_SUCCESS);
        }
    }
    return 0;
}

char showMenu()
{
    char menuId;
    printf("*********input some data*******************\n");
    printf("*********1)printf hi*******************\n");
    printf("*********2)printf hello*******************\n");
    fflush(stdin);
    menuId = getch();
    return menuId;
}
void pause(char msg[])
{
    printf("%s",msg);
    getch();
    printf("\n");
}

void test()
{
    int age;
    while(1){
        printf("input your age\n");
        fflush(stdin);
        scanf("%d",&age);
        if (age>0){
            break;
        }
    }
    printf("your age is %d\n",age);
    pause("press any key return ...");
}