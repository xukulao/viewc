//
// Created by Administrator on 2019/4/15.

#include <stdio.h>
int main()
{
    struct stu {
            char *name;
            short age;
            short num;
            char group;
            float score;
    };

//    struct stu student1,student2 = {"tony",10,20,'f',12.65};
//
//    student1.name = "张飞";
//    student1.age = 100;
//    student1.num = 101;
//    student1.group = 'm';
//    student1.score = 98.5;
//
//    printf("%s age is %d,his num is %d,and his group is %c,and his score is %.1f\n",
//            student1.name,student1.age,student1.num,student1.group,student1.score);
//
//    printf("%s age is %d,his num is %d,and his group is %c,and his score is %.1f\n",
//           student2.name,student2.age,student2.num,student2.group,student2.score);


      struct stu students[] = {
              "jack",10,101,'m',18.95,
              "tom",20,102,'f',29.98,
              "lucy",30,103,'m',39.83
      };

      int i;
      for(i=0;i< 3;i++){
          printf("student[%d]=%s,%d,%d,%c,%.1f\n",i,students[i].name,
                  students[i].age,students[i].num,students[i].group,students[i].score);
      }
}
