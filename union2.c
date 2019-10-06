//
// Created by Administrator on 2019/4/1
//

#include <stdio.h>
#include <stdlib.h>
//enum test {TOTAL=4};
#define TOTAL 4

struct {
    char name[20];
    int num;
    char sex;
    char professional;
    union {
        float score;
        char course[20];
    } s;
} bodys[TOTAL];

int main()
{

    int i=0;
    for(i=0;i<TOTAL;i++){
        printf("input info:");
        scanf("%s %d %c %c",bodys[i].name,&(bodys[i].num),&(bodys[i].sex),&(bodys[i].professional));

        if (bodys[i].professional == 's'){
            scanf("%f",&bodys[i].s.score);
        }else{
            scanf("%s",bodys[i].s.course);
        }

        //printf("%s\n",bodys[i].name);
        fflush(stdin);
    }

    printf("\nName\tNum\tSex\tProfession\tScore/Course\n");

    for(i=0;i<TOTAL;i++){
        if (bodys[i].professional == 's'){
            printf("%s\t%d\t%c\t%c\t%f\n",bodys[i].name,bodys[i].num,bodys[i].sex,bodys[i].professional,bodys[i].s.score);
        }else{
            printf("%s\t%d\t%c\t%c\t%s\n",bodys[i].name,bodys[i].num,bodys[i].sex,bodys[i].professional,bodys[i].s.course);
        }
    }

    return 0;
}
