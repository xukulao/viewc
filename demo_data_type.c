//
// Created by Administrator on 2019/3/30.
//
#include <stdio.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
void demo1()
{
    //2?????=16λ ??Чλ??15λ 32 768
//    short a = - 32768;
//    short b = 32768;
//
//    unsigned short c = 65535;
//
//    printf("%hd,%hd,%hu\n",a,b,c);
//    printf("%hd,%hd,%hd\n", sizeof(a), sizeof(b), sizeof(c));
//
//    short d = 0b00101010;
//    short e = 010;
//    short f = 0xef;
//
//    printf("%#hx,%#hx,%#hx\n",d,e,f);
//
//    short d1 = 0b10101010;
//    printf("%#hx\n",d+d1);


      short a = 0x11;//?з?????  ???λ?1???????
      //0x11 1000 0000 0001 0001 17
      //     1000 0000 0001 0001 ???
      //
      //

      printf("%hd\n",a);//???з?????????????????????????????


      printf("%hu\n",a);//?????????????????????????????????

      short b = -0x11;//?з?????  ???λ?1
      //-0x11 1000 0000 0001 0001
      //      1111 1111 1110 1110 ????
      //      1111 1111 1110 1111 ????

      //      ff ef

      printf("%#hX\n",b);//????з??????????????


      short c = -9;//?з?????????
      //1000 0000 0000 1001 ?????????
      //1111 1111 1111 0110 ?????????
      //1111 1111 1111 0111 ?????????

      //fff7

      printf("%#hX\n",c);//????????????
      printf("%hd\n",c);//??????????


}

/**
 * ????????????
 */
void demo2()
{

    short a1 = 0b01;
    short a2 = 0b10;
    /***
     * 0000 0000 0000 0001
     * 0000 0000 0000 0010
     * 0000 0000 0000 0011
     * 0003
     */
    printf("%#hx\n",a1+a2);

    short b1 = 0b111;
    short b2 = 0b111;
    /**
     * 0000 0000 0000 0111
     * 0000 0000 0000 0111
     * 0000 0000 0000 1110
     * 000e
     */
     printf("%#hX\n",b1+b2);


     short c1 = 0b0101;
     short c2 = 0b1010;

     /**
      * 0101
      * 1010
      * 0000 0000 0000 0001
      * 1111 1111 1111 1111
      */

     printf("%#hX\n",c1-c2);


     short d1 = 0b01011010;
     short d2 = 0345;
     short d3 = 0xafe;

     /**
      * 01011010
      * 2*6 2*4 2*3 2 = 2+8+16+64=90
      *
      * 3*8[2] + 4*8[1] + 5*8 = 5+32+195 = 232
      *
      * 10*16[2]+15*16[1]+14 = 14+2560+240 = 2814
      */

     printf("d1=%hd,d2=%hd,d3=%hd\n",d1,d2,d3);



     short e2 = 0234;
     short e3 = 0xaf;
     /**
      * 2*8[2]+3*8[1]+4   + 5*8[-1]=5/8 +4*8[-2]=4/64 + 2*8[-3]=2/512
      * 128+28=156.  0.625+0.0625+0.00390625 = 156.69140625
      *
      *
      *
      * 10*16[1]+15*1 =160+15=175 + 2*16[-1]=2/16 + 3*16[-2]=3/256 + 1*16[3]=1/4096
      * 175 0.125+0.01171875+0.0024449878
      * 175.1391637378
      */



     printf("e2=%hd,e3=%hd\n",e2,e3);

     short f1 = 100;
     /**
      * 100
      * 0110 0100 64
      *
      * 144
      */


     printf("f1=%#ho,f1=%#hx\n",f1,f1);

     short g1 = 0b10100001;
     /**
      * 241
      * a1
      *
      */

     printf("g1=%#ho,g1=%#hX\n",g1,g1);


}

void demo3()
{
    short a = 9;
    short b = 5;

    /***
     * ?????????????????????????
     * 9-5 = 9+(-5) ?????????????
     *0000 0000 0000 1001 ?????????????????????? 9
     *1000 0000 0000 0101 ?????????
     *1111 1111 1111 1010 ??????????
     *1111 1111 1111 1011 ??????????
     *
     *0000 0000 0000 1001 ???? 9
     *1111 1111 1111 1011 ???? -5
     *   1 0000  0000  0000 0100 ???? ????1
     *   0000 0000 0000 0100 ??????????
     *   0000 0000 0000 0100 ????
     *   0000 0000 0000 0100 ???
     */

    printf("%#hX\n",a-b);
    short c = 5;
    short d = 19;

    /**
     * 5-19  5+(-19)????????
     * 0000 0000 0000 0101 5?????
     * 1000 0000 0001 0011 19?????
     * 1111 1111 1110 1100 ????
     * 1111 1111 1110 1101 ????
     *
     * 0000 0000 0000 0101
     * 1111 1111 1110 1101
     * 1111  1111  1111  0010 ???????????油??
     * fff2
     * 1111 1111 1111 0001 ????
     * 1000 0000 0000 1110 ??? ???
     *
     *?ó????????????洢??????????????????????
     */
    printf("%#hX\n",c-d);
    short e = -0x1;
    /**
     * 1000 0000 0000 0001 ???
     * 1111 1111 1111 1110 ????
     * 1111 1111 1111 1111 ????
     * ffff
     */

    printf("%#hX\n",e);

}

void demo4()
{
    float a = 1.0012;
    float b = 0.8e10;//0.8*10??10?η?
    float c = 0.92E-1;//0.92*10??-1?η?
    double d = 0.23e10;//0.23*10??10?η?

    printf("%f\n",a);
    printf("b=%e,b=%f\n",b,b);
    printf("c=%e,c=%f\n",c,c);
    printf("d=%lf,d=%le\n",d,d);
}

void demo5()
{
    char a = 'a';
    char b = 'b';
    putchar(a);
    putchar(b);
    printf("a=%c,b=%c\n",a,b);

    printf("a=%#hX\n",a);

    int c = 65;
    char d = 'q';
    printf("%c,%d,%x\n",c,c,c);
    printf("%c,%d,%x\n",d,d,d);
}

void char_demo6()
{
    char *p = "php is best language";
    char a[] = "一起出去浪！";

    puts(p);
    printf("%s\n",a);
}

//宽字符测试

void wchar()
{
    wchar_t a = L'中';
    wchar_t b = L'国';
    wchar_t c = L'c';

    setlocale(LC_ALL,"zh-CN");
    putwchar(a);
    //wprintf(L"%c\n",b);
    //putwchar(c);

    //wprintf(L"a=%d\n", sizeof(a));
    //wprintf(L"c=%d\n", sizeof(c));
}

//转义字符
void escchar()
{
    char a = '\61';
    char b = '\x31';
    char c = '\x80';

    printf("a=%c,b=%c,c=%c\n",a,b,c);
    char *d1 = "\x31\x32\x33\x61\x62\x63";
    char *d2 = "\x61\x62\x88";

    printf("d1=%s,d2=%s\n",d1,d2);
    printf("\x31\x32\x33\x61\x62\x63");
}

//四则运行测试
void base_operator()
{

    int a = 100;
    short b = 10;
    long c = 9325;

    float d = 12.43;
    double d1 = 1.0921;

    printf("a+b=%d\n",a+b);
    printf("a+c=%ld\n",a+c);
    printf("d+d1=%lf\n",d+d1);

    printf("a+d=%d\n",a+d);
    printf("a+d=%lf\n",a+d);

}

void plusminus()
{
    int a = 10;
    int b = 10;
    --a;
    --b;
    printf("a=%d,b=%d\n",a,b);

    int c = 10;
    int d = 10;
    c++;
    d++;
    printf("c=%d,d=%d\n",c,d);

    //
    int a1 = 20,b1=20,c1=20,d1=20;
    int a2 = ++a1;//21 a1先自增得21，再赋值
    int b2 = --b1;//19 b1先自减得19，再赋值
    int c2 = c1++;//20 c1先赋值给c2,再自增得21
    int d2 = d1--;//20 d1先赋值给d2,再自减得19

    printf("a1=%d,b1=%d,c1=%d,d1=%d\n",a1,b1,c1,d1);
    printf("a2=%d,b2=%d,c2=%d,d2=%d\n",a2,b2,c2,d2);
}

int variable_position_i = 100;
void variable_positaion()
{
    float a = 89.01;
    char *c = "我们转圈圈";
    printf("variable_position_i=%d,a=%hf,c=%s\n",variable_position_i,a,c);
}

int var_init_value_i;
void var_init_value()
{

    float a;
    int b;
    long c;

    printf("var_init_value_i=%d,a=%hf,b=%d,c=%ld\n",var_init_value_i,a,b,c);
}


void printf_function()
{
    char *name1 = "tony";
    int age1 = 100;
    int height1 = 190;

    char *name2 = "jack";
    int age2 = 23;
    int height2 = 170;

    char *name3 = "lucy";
    int age3 = 32;
    int height3 = 160;

    printf("%-9s%-9s%-9s\n","name","age","height");
    printf("%-9s%-9d%-9d\n",name1,age1,height1);
    printf("%-9s%-9d%-9d\n",name2,age2,height2);
    printf("%-9s%-9d%-9d\n",name3,age3,height3);



   /* int n = 234;
    float f = 9.8;
    char c = '@';
    char *str = "http://www.baidu.com";

    //[flag][width][.precision][type]
    //width 不够被空格，超过原样输出
    printf("%10d%12f%4c%8s",n,f,c,str);
*/

    //.precision 整数不够左边加0  超过原样输出
    //小数 够就照样输出，不够就在右边加0
    //字符 够就照样输出，超出原样输出
    /*
    int n = 123456;
    double f = 882.923672;
    char *str = "abcdefghi";
    printf("n: %.9d  %.4d\n", n, n);
    printf("f: %.2lf  %.4lf  %.10lf\n", f, f, f);
    printf("str: %.5s  %.15s\n", str, str);
     */


    /*int n = 123;
    float f = 123.654;
    char *str = "hello";

    printf("%.5d,%.2d\n",n,n);//00123 123
    printf("%.5f,%.1f\n",f,f);//123.65400 123.65

    printf("%.10s,%.3s",str,str);//hello,hel*/

    /*
    int m = 192, n = -943;
    float f = 84.342;
    printf("m=%10d, m=%-10d\n", m, m);  //演示 - 的用法
    printf("m=%+d, n=%+d\n", m, n);  //演示 + 的用法
    printf("m=% d, n=% d\n", m, n);  //演示空格的用法
    printf("f=%.0f, f=%#.0f\n", f, f);  //演示#的用法


     */

    printf("baidu.com\n");

    sleep(5);

    printf("http://www.baidu.com\n");
}


void snake()
{

    COORD coord;
    coord.X = 3;
    coord.Y = 3;

    HANDLE ConsoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(ConsoleHandler,coord);

    printf("123");
    getchar();
}

void scanf_function()
{
    int a = 0;
    int b = 0;
    int c = 0;
//    int d = 0;
//    printf("please enter your data:\n");
//    scanf("%d\n",&a);
//    scanf("%d\n",&b);
//
//    printf("a+b=%d\n",a+b);
//
//    scanf("%d %d\n",&c,&d);
//    printf("c+d=%d\n",c+d);
//
//      scanf("%d %d",&a,&b);
//      printf("a+b=%d\n",a+b);
//      scanf("%d     %d",&a,&b);
//      printf("a+b=%d\n",a+b);
//
//      scanf("%d,%d,%d",&a,&b,&c);
//      printf("a+b+c=%d\n",a+b+c);
//
//      scanf("%d is bigger than %d",&a,&b);
//      printf("a-b=%d\n",a-b);

//        float age = 0;
//        char name[] = "";
//
//        scanf("%f",&age);
//        scanf("%s",name);
//        printf("your name is %s,and your age is %.2f\n",name,age);

        char author[30];
        char language[30];
        char url[100];
        scanf("%s %s",author,language);
        printf("author=%s,language=%s\n",author,language);
        scanf("%s",url);
        printf("url=%s\n",url);

}

void address()
{
    short int a = 1;//占2个字节
    short int b = 2;
    short int c = 3;

    printf("a=%p,b=%p,c=%p\n",&a,&b,&c);

    //62FDEA 62FDEB 62FDEC 62FDED 62FDEE 62FDEF
}

void getchar_test()
{
    char a;
    a = getchar();
    if (a){
        printf("c=%c\n",a);
    }else{
        printf("please enter a character!");
    }
}


void getche_test()
{
    char a;
    a = getche();
    printf("%c\n",a);
}

void getch_test()
{
    char a;
    a = getch();
    printf("%c\n",a);
}

void gets_test()
{
    char name[30];
    char url[100];

    gets(name);
    gets(url);

    printf("name=%s,url=%s\n",name,url);
}

/**
 * 第一行输出，先到输出缓冲区里待着，然后再和后面的第二行一起输出的 linux是这样的
 * win就不是了
 *
 * 缓冲区【内存】
 * 输出缓冲：当使用printf函数时，它会从输出缓冲区里读取数据，遇到换行符号时，读取结束，并清空缓冲区，数据传递到显示器显示
 * 输入缓冲：当使用scanf函数时，它会从输入缓冲区里读取数据，从第一个地址开始匹配格式式指定的类型，当遇到换行符时，刷新缓冲区，并将数据赋值给变量
 *
 */
void cache_test()
{
//    printf("hello,php");//理论上是输出到缓冲区【内存】
//    sleep(5);
//    printf("nihao,php\n");//遇到换行后一起输出到显示器【硬件】

    printf("%d\n",220*3);
}

void scanf_advance_test()
{

//    int n;
//    float f;
//    char str[23];
//
//    scanf("%2d",&n);//读取指定长度的数字
//    scanf("%*[^\n]");scanf("%*c");//清空缓冲区
//    scanf("%5f",&f);
//    scanf("%*[^\n]");scanf("%*c");
//    scanf("%22s",str);
//
//    printf("n=%10d,f=%10f,str=%s\n",n,f,str);

//      char str[30];
//      char str1[10];
//      scanf("%[abcd]",str);//只读取含有abcd的数据
//      scanf("%*[\n]");scanf("%*c");
//      scanf("%*[^0123456789]",str1);
//      printf("%s\n",str);
//      printf("%s\n",str1);

//    char str[30];
//    int n=0;
//    scanf("%[a-zA-Z]",str);//类似正则  只匹配以小写字母或大写字母
//
//    //scanf("%*[^\n]");scanf("%*c");
//    scanf("%[0-9]",&n);
//    printf("str=%s\n",str);
//    printf("n=%d\n",n);

    //char str1[30];char str2[30];
   // int n;
    //scanf("%[^0-9]",str1);//匹配非数字
    //scanf("%*[^\n]");scanf("%*c");
    //scanf("%[^\n]",str2);//匹配非换行符号
    //scanf("%*[^\n]");scanf("%*c");
    //scanf("%[0-9]",str2);//匹配非换行符号

    //printf("str1=%s,str2=%s\n",str1,str2);

    //scanf("%30[^0-9]",str1);
    //printf("str1=%s\n",str1);

//    scanf("%*d %d",&n);//第一个读取的数字全丢弃  第二个给变量n
//    scanf("%*[a-z]");//所有字母全丢弃清空
//    scanf("%[^\n]",str1);//不是换行符的全部清空丢弃
//
//    printf("n=%d,str1=%s\n",n,str1);



     char str[30];
     char str2[30];
     int n = 0;

//     scanf("%[a-zA-Z]",str);//先从输入缓冲区开始匹配大小写字母
//     scanf("%*[0-9]");//再从缓冲区【指定的位置】开始匹配所有数字
//     scanf("%[a-z]",str2);//再匹配小写字母
//
//     printf("str=%s,str2=%s,n=%d\n",str,str2,n);

//     scanf("%[a-zA-Z]",str);
//     scanf("%*[^\n]");
//     scanf("%[0-9]",&n);
//     printf("your name is %s,and your age is %d\n",str,n);


      char name[10];
      int age;
      char url[100];
      //printf("your name is:\n");
      scanf("%10[a-z]",name);
      //printf("your age is:\n");
      scanf("%d",&age);
      //printf("your url is:\n",url);
      scanf("%[a-z.]",url);

      printf("ok,your info of name is %s,age is %d,url is %s\n",name,age,url);
}

/**
 * 模拟密码输入
 * @param pwd
 * @param pwdlength
 */
void pwd_test(char *pwd,int pwdlength)
{
    char ch = 0;
    int i = 0;

    while(i<pwdlength){

        ch = getche();
        if (ch == '\r'){
            printf("\n");
            break;
        }else if(ch == '\b' && i>0){
            printf("\b \b");
            i--;
        }else if(isprint(ch)){
            pwd[i] = ch;
            printf("*");
            i++;
        }
    }

    pwd[i] = 0;//最后一位
}

void if_test()
{
//    char age = 0;
//    printf("please enter your age");
//    scanf("%d",&age);
//    if (age > 18){
//        printf("ok");
//    }else{
//        printf("no");
//    }

//    int a,b,max;
//    printf("please enter some data:\n");
//    scanf("%d %d",&a,&b);
////    if (a>b)max=a;
////    else max=b;
//
//    //max = (a>b)?a:b;
//    max = b;
//    if(a>b)max=a;
//    printf("max is %d\n",max);

      //int age,score;
     // printf("please enter your age and your score:\n");
      //scanf("%d %d",&age,&score);
//      if (age >18){
//          if (score >=60){
//              printf("ok,u can do it");
//          }else{
//              printf("sorry,u can't do it!");
//          }
//      }else{
//          printf("sorry,u can't use it");
//      }
//     if(age>18 && score >=60){
//         printf("u can do it!");
//     }else{
//         printf("u can not do it!");
//     }
       //if(age>=18&&score>=60)printf("u can do it!");
      // else printf("u can not do it!");

//      int day;
//      while (1){
//          scanf("%d",&day);
//          switch (day){
//              case 1:
//                  printf("Monday!\n");
//                  //scanf("%d",&day);
//                  break;
//              case 2:
//                  printf("Tuesday!\n");
//                  //scanf("%d",&day);
//                  break;
//              case 3:
//                  printf("Wednesday!\n");
//                  //scanf("%d",&day);
//                  break;
//              case 4:
//                  printf("Thurday!\n");
//                  scanf("%d",&day);
//                  break;
//              case 5:
//                  printf("Friday!\n");
//                  //scanf("%d",&day);
//                  break;
//              case 6:
//                  printf("Saturday!\n");
//                  //scanf("%d",&day);
//                  break;
//              case 7:
//                  printf("Sunday!\n");
//                  scanf("%d",&day);
//                  break;
//              default:
//                  printf("no!\n");
//                  //scanf("%d",&day);
//                  break;
//          }
//      }

      long int i=0;
      while(1){

          printf("%d\n",++i);
          if (i == 100000000){
              break;
          }
      }
}

void ninetonine()
{
    int i;
    int j;
    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){

            if ((i-j)<=0){
                printf("%2dx%2d=%2d",i,j,i*j);
            }

        }
        printf("\n");
    }
    getchar();
}

void countCharAndNumAndOther()
{
    printf("please enter some data:\n");
    char str[50];
    scanf("%[a-z]",str);
    scanf("%[A-Z]",str);
    scanf("%[0-9]",str);

}

void square()
{
    int num;
    scanf("%d",&num);
    for(int j=1;j<num;j++){
        if (num/2==j){
            for(int m=num-j;m>0;m--){

               for(int k=m;k>=0;k--){
                   printf(" ");printf("*");
               }
               printf("\n");


            }
        }else if(j<=num/2){

            for(int n=0;n<j;n++){
                printf(" ");printf("*");
            }
            printf("\n");
        }
    }

}

//内存测试  分配内存
void memory_test()
{
    while (1){

        malloc(1024);
    }
}
