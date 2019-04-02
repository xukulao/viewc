#ifndef __DEMO_DATA_TYPE__
#define __DEMO_DATA_TYPE__

void demo1();

void demo2();

void demo3();

void demo4();

void demo5();

//ASCII字符
void char_demo6();
//宽字符
void wchar();

//转义字符
//字符集【字符-编码值】
//http://c.biancheng.net/cpp/html/2890.html
void escchar();

//四则运行
void base_operator();

//自增和自减
void plusminus();

//变量的位置与初始化
void variable_positaion();

//变量的初始值
void var_init_value();

//printf骚用法
void printf_function();

//一个小游戏
void snake();

//scanf用法
void scanf_function();

//address 测试
void address();

//getchar 测试
void getchar_test();

//getche测试
void getche_test();

//getch测试
void getch_test();

//gets 测试
/**
 * getchar 获取输入的一个字符 stdio
 * getche 获取输入的一个字符  无缓冲  conio.h
 * getch 同样
 *
 * gets 获取输入的字符串  遇到回车结束输入
 * scanf 遇到空格结束输入
 */
void gets_test();
#endif