//
// Created by Administrator on 2019/4/16.
//

#include <stdio.h>

int main()
{
    struct stu {
        char *name;
        short int age;
        short int height;
    };

//    struct stu student1;
//    struct stu student2;
//
//    student1.age = 100;
//    student1.name = "jack";
//    student1.height = 180;

    //printf("my name is %s,age is %d,height is %d\n",student1.name,student1.age,student1.height);
    struct stu students[2] = {
            {"jack",20,180},
            {"tom",30,190}
    };

    struct stu *p[2] = students;
    printf("p=%#x,student[0]=%#X,students[0].name=%#X\n",p,&students[0],&students[0].name);
    printf("p[0].name=%s\n",*p[0].name);
//    int i;
//    for(i=0;i<2;i++){
//        printf("%s `s age is %d ,his height is %d\n",students[i].name,students[i].age,students[i].height);
//        printf("%s\n",*p[i].name);
//    }
    return 0;
}