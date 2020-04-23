//
// Created by Administrator on 2019/4/30.
//

#include <stdio.h>
static int m=10;
static struct person {
    char name[20];
    int age;
    int num;
}tony={"tony",20,100};
static void showMM()
{
    printf("m=%d\n",m);
    printf("%s is %d\n",tony.name,tony.age);
}
static struct person {
    char name[20];
    int age;
    int num;
}tony={"tony1",202,1002};

void show()
{
    showMM();
}
