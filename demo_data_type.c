//
// Created by Administrator on 2019/3/30.
//
#include <stdio.h>
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
#include <wchar.h>
#include <locale.h>
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

#include <unistd.h>
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

#include <windows.h>
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

#include <conio.h>
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