//
// Created by Administrator on 2016/4/17.


#include <stdio.h>
typedef char STRING[20];
typedef char MAX_STRING[500];

typedef unsigned int UINT;
typedef  float FLOAT;

typedef char *STR;
typedef struct person{
    STR name;
    UINT age;
    FLOAT score;
    struct person *tom;
}PERSON;

//二维数组指针
typedef int (*AGE)[2];
//函数指针 返回值为指针
typedef int *(*function)(int ,int)

int *max(int a,int b);
int main()
{

    PERSON tony;
    tony.name = "china";
    tony.age = 100;
    tony.score = 100.234;

    printf("name=%s,age=%d,score=%.2f\n",tony.name,tony.age,tony.score);

    char a[20] = "cina";
    STRING b = "ok";
    printf("a=%s\n",b);

    int age[2][2] = {
            {100,200},
            {300,500}
    };
    AGE tonyAge = age;//tonyAge=age age=&age[0] age[0] = &age[0][0]

    int (*p)[4];

    printf("tony's age %d\n",**tonyAge);
    printf("tony's age %d\n",*(*(tonyAge+1)));

    function functionMax= max;

    printf("max=%d\n",*functionMax(10,30));

    tony.tom = &tony;

    printf("score=%.1f",tony.tom->score);

    return 0;

}

int *max(int a,int b)
{
    int *temp;
    if (a>b){
        temp = &a;
    }else{
        temp = &b;
    }
    return temp;
}
