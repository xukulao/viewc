//
// Created by 1655664358@qq.com on 2019/5/8.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void pause(char msg[]);
char showMenu();
void test();
struct STU{
    int id;
    char name[20];
    char sex[4];
};
typedef struct _NODE{
    struct STU data;
    struct _NODE *next;
} NODE;
int main()
{
    int id;
//    while(1){
//        id = showMenu();
//        switch (id){
//            case '1':
//                test();
//                break;
//            case '2':
//                printf("hello\n");
//                pause("enter any key return ...");
//                break;
//            case '0':exit(EXIT_SUCCESS);
//        }
//    }

    int *age = (int *)malloc(10* sizeof(int));
    age[0] = 1;
    age[1] = 2;
    printf("age[0]=%d,age[0]=%d\n",age[0],*age);
    printf("age=%d,age[0]=%d\n", sizeof(age[0]), sizeof(age[1]));

    NODE node1;
    node1.data.name[0] = 'j';
    node1.data.sex[0] = 'n';
    node1.data.id = 100;
    printf("node=%d\n",node1.data.id);
    node1.next = &node1;
    printf("node2=%d\n",node1.next->id);
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