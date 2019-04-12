//
// Created by Administrator on 2019/3/29.
//
#include <stdio.h>
#include "demo_data_type.h"
int age = 99999;
char name[100] = "jackchensm";

/********************define******************************/

#define M 120
//#define 打印 printf("hello")
#define PI 3.1415926
#define S PI+100
#define UINT unsigned int
#define PIN int *
typedef int *PINT2;

#define J(y) y+100
#define MAX(a,b) a>b?a:b

#define SQ(y) ((y)*(y))
#define CON(a,b) a##b##100

/********************define******************************/

int main()
{
//    puts("php is best language in the world2");
//
//    //1010 1011 = 0xab
//    //
//    printf("%c\n",0x4C7C3355);
//
//    getchar();

    //demo1();
    //demo2();
//    demo3();
    //demo4();
   // demo5();
  // char_demo6();
  //wchar();
  //escchar();
   //base_operator();
   //plusminus();
   //variable_positaion();
   //var_init_value();
   //printf_function();
   //snake();
   //scanf_function();
   //getchar_test();
   //getche_test();
   //getch_test();
   //gets_test();
   //address();
   //cache_test();
   //scanf_advance_test();

//   char pwd[21];
//   int pwdlenght = 20;
//
//   printf("enter your pwd:\n");
//   pwd_test(pwd,pwdlenght);
//   printf("your pwd is：%s\n",pwd);
//   getchar();

     //if_test();
     //ninetonine();
     //square();
     //memory_test();
     //array_test1();
     //array_test2();
     //array_test3();
     //array_search();
     //array_search1();
     //char_array();
     //strcat_test();
     //strcopy_test();
    //insertOrDeleteArray();
    //outOfArray();
   // BubbleArray();
   // array_search_test1();
//    int a[10] = {10,30,60,65,70,80,85,88,90,99};
//    int key;
//    for(int i=0;i<10;i++){
//        printf("%d\t",a[i]);
//    }
//    printf("\n");
//    scanf("%d",&key);
//    int ret;
//     ret=array_search2(key);
//    if (ret == -1){
//        printf("no result");
//    }else{
//        printf("ok,find it!");
//    }

    //int ret = sum_test();
    //int ret = sum_test1(1,10);
//    int ret = 0;
//    int m = 0;
//    int n = 0;
//    while(1){
//        printf("enter some data\n");
//        scanf("%d,%d",&m,&n);
//        if (m>0&&n>0){
//            ret = sum_test1(m,n);
//            printf("ret=%d\n",ret);
//        }else {
//            break;
//        }
//    }

    //printf("sum_test2() = %d\n",sum_test2(10));
    //printf("age=%d,name=%s\n",age,name);
    //printf("sum=%d\n",factoria2(5));

    //char str[20] = "123456789";
    //printf("str=%s\n",reverse(str));


//    printf("m=%d\n",M);
//    printf("m=%d\n",M);
//    printf("m=%d\n",M);
//      printf("S=%f\n",S);
//
//      UINT i;
//      i=100;
//      printf("i=%d\n",i);

//    PIN a,b;//int *a,b
//    b = 100;
//    a = &b;
//
//    PINT2 c,d;//int *c,int *d
//    c = a;
//    d = a;
//    //printf("a=%d,b=%d,c=%d,d=%d\n",*a,b,*c,*d);
//    printf("%s\n","hello");
//    printf("c=%d\n",*c);

    //printf("J=%d\n",J(100));
//    int a,b;
//    //scanf("%d,%d",&a,&b);
//    scanf("/[0-9]+/",&a);
//
//    scanf("/[0-9]+/",&b);
//    printf("a>b=%d\n",MAX(a,b));

       // test_sqt();
//       int i=0;
//       while(i<=5){
//           printf("%d^2=%d\n",i,SQ(i++));
//       }

//预定义宏
//    printf("con=%d\n",CON(100,200));
//    printf("date=%s\n",__DATE__);
//    printf("time=%s\n",__TIME__);
//    printf("line=%s\n",__LINE__);
//    printf("file=%s\n",__FILE__);
//    printf("func=%s\n",__FUNCTION__);
//    system("pause");

    //条件编译
//#if _WIN32
//printf("hello,windows");
//#elif
//printf("hello,linux")
//#endif

//是否定义了宏名
//#ifdef M
//printf("m=%d\n",M);
//#endif

//#ifndef CHINESE
//#define CHINESE 10000
//#ifdef CHINESE
//printf("chinese=%d\n",CHINESE);
//#endif
//#endif
//
//#undef JAPANESE
//#define JAPANESE 100
//
//printf("japanese=%d\n",JAPANESE);

//#ifdef WIN32
//#error not support windows!
//printf("not support windows!");
//#endif

//#undef M
//#ifdef M
//printf("m=%d\n",M);
//#endif
//    return 0;

//int a=10;
///***
// * 变量类型 int
// * 变量名称 a
// * 变量内存大小  4b
// * 变量内存编号【地址】【指针】  0X62FE1C
// */
//
//char name[] = "chinese";
///**
// * 变量类型 char
// * 变量名称 name
// * 变量内存大小 1b
// * 变量内存编号【地址】【指针】 0X62FE10
// */
//
//int *p;
///**
// * 变量类型  指针int
// * 变量名称 p
// * 变量内容 变量a的内存地址【指针】 0X62FE1C
// * 变量内存大小  4b
// * 变量内存编号【地址】【指针】0X62FE08
// */
//p = &a;
//printf("%#X,%#X\n",&a,name);
//printf("%d,%d,p=%d,p=%#X\n",*&a,name[0],*p,&p);

//pointer1();
//pointer2();
//pointer3();
//array_pointer1();
//array_pointer2();
//array_pointer3();

//array_char_pointer1();
//array_char_pointer2();
//array_char_pointer3();
//
//int a = 10;
//int b = 20;
//
//swap_pointer1(&a,&b);
//printf("a=%d,b=%d\n",a,b);

//int num[6];
//int len = sizeof(num)/ sizeof(int);
//int i;
//for(i=0;i<len;i++){
//    scanf("%d",num+i);
//}
//
//printf("maxValue=%d\n",array_max_pointer1(num,len));
//
//char str[30],str1[30],*str2;
//gets(str);
//gets(str1);
//
//str2 = longStr(str,str1);
//printf("longStr=%s\n",str2);

//int *p,n;
//p = func_test();
//    printf("test func");
//n = *p;
//
//printf("n=%d\n",n);

//null_pointer();
    char *str;
    gets(str);
    printf("str=%s\n",str);
return 0;

}
