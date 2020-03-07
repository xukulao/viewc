//
// Created by Administrator on 2017/4/18

#include <stdio.h>
#define N 2
struct stu
{
    char name[20];
    int num;
    int age;
    float score;
}bodya[N],bodyb[N],*pa,*pb;
int main()
{

    pa = bodya;
    pb = bodyb;
    char *fileName = "E:/c/demo/hello.txt";
    FILE *file = fopen(fileName,"wb+");
    if(file == NULL){
        printf("not found file!");
    }

    int i=0;
    for(i;i<N;i++,pa++){ //pa=bodya[0] pa=bodya[1]
        scanf("%s %d %d %f",pa->name,&pa->num,&pa->age,&pa->score);
    }

    fwrite(bodya, sizeof(struct stu),N,file);

    rewind(file);

    fread(bodyb, sizeof(struct stu),N,file);

    printf("Name\t\tAGE\t\tNum\t\tSCORE\n");
    for(i=0;i<N;i++,pb++){
        printf("%s\t\t%d\t\t%d\t\t%.2f\n",pb->name,pb->age,pb->num,pb->score);
    }
    return 0;
}
