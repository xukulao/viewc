//
// Created by Administrator on 2019/4/17.
//

#include <stdio.h>

int main()
{

    union data {
        short int a;
        char age;
        float height;
    };

    union data who;
    union data what;

    printf("who=%d,union data =%d\n", sizeof(who), sizeof(union data));

    who.a = 100;
    who.age = 1;
    who.height = 187.43;
    who.a = 900;

    printf("who.age=%hd,who.age=%d,who.height=%.2f\n",who.a,who.age,who.height);

    //共用体指针
    union data *which = &who;
    printf("which.a=%d,which.age=%d,which.height=%.2f\n",which->a,which->age,which->height);

    return 0;
}