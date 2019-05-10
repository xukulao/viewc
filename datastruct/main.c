//
// Created by 1655664358@qq.com on 2019/5/10.
//

#include <stdio.h>
#include <string.h>
typedef struct test{
    char *address;
    char name[20];
}t;
int main()
{
    char *name;
    name = "china";
    printf("name=%s\n",name);
    t t1;
    t1.address = "bejing";
    printf("t=%s\n",t1.address);

    strcpy(t1.name,"guiyang");
    printf("name=%s\n",t1.name);
    char *name1 = "lucy";
    t1.name[0] = 'c';
    printf("name1=%s\n",t1.name);

    char name2[20] = "test";
    //t1.name = name2;

    sprintf(t1.name,"%s","hello");
    printf("name133=%s\n",t1.name);

    strcat(t1.name,"nihao");
    printf("name133333=%s\n",t1.name);
//    t.家乡[0] = 'j';
//    printf("[0]=%c\n",t.家乡);

    t1.name->"ok";
    printf("%s\n",t1.name);

    return 0;
}