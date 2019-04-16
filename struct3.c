//
// Created by Administrator on 2019/4/16.
//

#include <stdio.h>
int main()
{
    struct stu {
        char *name;
        short age;
        short height;
        char *adddress;
    };

    struct stu student = {"tom",100,190,"beijing"};
    struct stu *s = &student;

    struct stu **sa = &s;

    printf("%s 's age is %d,and his height is %d,and his address location %s\n",s->name,s->age,s->height,s->adddress);
    printf("%s 's age is %d,and his height is %d,and his address location %s\n",(*sa)->name,
           (*sa)->age,(*sa)->height,(*sa)->adddress);

    printf("%s 's age is %d,and his height is %d,and his address location %s\n",(**sa).name,
           (**sa).age,(**sa).height,(**sa).adddress);
}