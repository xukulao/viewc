//
// Created by Administrator on 2019/4/16


#include <stdio.h>
struct stu {
    char *name;
    short age;
    short height;
    float score;
    char *address;
} students[]={
        {"lili",10,150,140,"shanghai"},
        {"jack",20,160,143.24,"beijing"},
        {"tom",30,160,120,"suzhou"},
        {"tony",50,140,150,"kongkong"},
        {"lucy",60,160,130.54,"guizhou"}
};




void average(struct stu *ps,int len);
int main()
{
    average(students, sizeof(students)/ sizeof(struct stu));

    /**
     * 结构体数组指针
     */
    struct stu *p[5] = {students,students,students,students,students};

    //p = &p[0] p[0]的机器地址  p[0]=students机器地址 students = students[0]的机器地址 students[0] = students[0][0]的机器地址
    printf("students[0]=%#X,students[0]=%#X\n",p,&p[0]);
    printf("students[0]=%#X,students[0]=%#X\n",p[0],&students);
    printf("students[0]=%#X,students[0]=%#X\n",students,&students[0]);



    printf("students[0]=%s\n",(*p)->name);
//    printf("students[1]=%d\n",(*p+0)->age);
//
//    printf("students[0]=%s\n",(*p+1)->name);
//    printf("students[1]=%d\n",(*p+1)->age);

//    printf("students[0]=%s\n",(p[1]+1)->name);
//    printf("students[0]=%s\n",(p[2]+2)->name);
//    printf("students[0]=%s\n",(p[3]+3)->name);
//    printf("students[0]=%s\n",(p[4]+4)->name);

    printf("students[0]=%s\n",(p[1]+1)->name);
    printf("students[0]=%s\n",(p[1]+2)->name);
    printf("students[0]=%s\n",(p[1]+3)->name);
    printf("students[0]=%s\n",(p[1]+4)->name);


    printf("students[0]=%#X\n",(p[1]));
    printf("students[0]=%#X\n",&students[0]);

    /**
     * *p[5] = {arr1,arr2}
     * arr1 = [1,2,3,4,5]   p=p[0] p[0]=arr1 arr1=arr1[0]
     *                      p[1]=arr1 arr1=arr1[0]
     */

    printf("****************************************************************\n");
    printf("students[0]=%#X,students[0]=%#X\n",p,&p[0]);
    printf("students[0]=%#X,students[0]=%#X\n",p[0],&students);
    printf("students[0]=%#X,students[0]=%#X\n",students,&students[0]);

    printf("****************************************************************\n");
    printf("student[1]=%#X,student[1]=%#X\n",p[1],students);
    printf("student[1]=%#X,student[1]=%#X\n",students,&students[0]);

    printf("*****************************************************************\n");
    printf("students[0]=%s\n",(*p+1)->name);//p = &p[0]
    printf("students[0]=%s\n",(*p+2)->name);
    printf("students[0]=%s\n",(*p+3)->name);
    printf("students[0]=%s\n",(*p+4)->name);

    printf("*****************************************************************\n");
    printf("students[0]=%s\n",(p[0]+1)->name);//p = &p[0]
    printf("students[0]=%s\n",(p[0]+2)->name);
    printf("students[0]=%s\n",(p[0]+3)->name);
    printf("students[0]=%s\n",(p[0]+4)->name);

    printf("*****************************************************************\n");
    printf("students[0]=%s\n",(p[2]+1)->name);//p = &p[0]
    printf("students[0]=%s\n",(p[2]+2)->name);
    printf("students[0]=%s\n",(p[2]+3)->name);
    printf("students[0]=%s\n",(p[2]+4)->name);
    return 0;

}

void average(struct stu *ps,int len)
{
    float sum,average;
    int i;
    int num_140=0;
    for(i=0;i<len;i++){
        sum+=(ps+i)->score;
        if((ps+i)->score<140)num_140++;
    }

    printf("sum=%.2f,average=%.1f,num_140=%d\n",sum,sum/5,num_140);

}
