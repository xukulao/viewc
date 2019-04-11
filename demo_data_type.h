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

//缓冲区测试 http://c.biancheng.net/cpp/html/2413.html
void cache_test();

//scanf advance test
void scanf_advance_test();

//pwd
void pwd_test();


//if
void if_test();

void ninetonine();

void countCharAndNumAndOther();
void square();

void memory_test();

void array_test1();

void array_test2();

void array_test3();

void array_search();

void array_search1();

//字符数组
void char_array();

//字符串处理
void strcat_test();
void strcopy_test();

//数组删除，增加
void insertOrDeleteArray();

//数组溢出和越界
void outOfArray();

//冒泡算法
void BubbleArray();

//二分查找算法
int array_search2(int key);

void array_search_test1();

//function test
int sum_test();

int sum_test1();

long factoria1(int n);
long sum_test2(int n);

long factoria2(int n);

char *reverse(char *str);

//
int sqt(int y);
void test_sqt();

//指针
void pointer1();

void pointer2();

void pointer3();

//数组指针
void array_pointer1();
#endif