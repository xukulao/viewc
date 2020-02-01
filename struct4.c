//
// Created by Administrator on 2016/4/1.
#include <stdio.h>

int main()
{

    struct stu{
        char *name;//4*2 = 8
        short age;//4*2  =8
        short height;//4*2 = 8
        char *address;//4*6 24
    } *p,students[2] = {
            {"jack",100,190,"beijing"},
            {"tom",500,200,"american"}
    };

    p = students;

    //printf("students=%d\n", sizeof(students)/ sizeof(struct stu));
    int len = sizeof(students)/ sizeof(struct stu);
    for(p=students;p<students+len;p++){
        printf("%s 's age is %d,and his height is %d\n",p->name,p->age,p->height);
    }


    printf("students[0].name=%s\n",students->name);
    printf("students[1].name=%s\n",(students+1)->name);
    int i;
    for(i=0;i<2;i++){

        printf("%s\n",(students+i)->name);
    }

    struct stu *k = students;
    printf("%s\n",*&(k++)->name);
}
