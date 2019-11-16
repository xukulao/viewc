//
// Created by Administrator on 2019/4/1
//

#include <stdio.h>
#define N 2
struct stu
{
    char name[20];
    int num;
    int age;
    float score;
}stu2[N],stu1[N],*pa,*pb;
int main()
{
    pa = stu1;
    pb = stu2;
    char *fileName = "E:/c/demo/hello.txt";
    FILE *file = fopen(fileName,"wb+");
    if (file == NULL){
        printf("not found error!");
        system("exit");
    }
    int i;
    //获取输入的数据
    for(i=0;i<N;i++,pa++){
        scanf("%s %d %d  %f",pa->name,&pa->num,&pa->age,&pa->score);
    }
    pa = stu1;
    //按格式写入文件
    for(i=0;i<N;i++,pa++){
        fprintf(file,"%s %d %d %f\n",pa->name,pa->num,pa->age,pa->score);
    }

    rewind(file);

    //读取的数据放入pb
    for(i=0;i<N;i++,pb++)
    {
        fscanf(file,"%s %d %d %f\n",pb->name,&pb->num,&pb->age,&pb->score);
    }

    pb = stu2;

    for(i=0;i<N;i++,pb++)
    {
        printf("%s\t%d\t%d\t%.1f\n",pb->name,pb->num,pb->age,pb->score);
    }

    fclose(file);
    return 0;
}
