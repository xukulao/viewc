//
// Created by 1655664358@qq.com on 2019/5/15.
//
/**
 * 大端模式：数据高位存低位  数据低位存地址高位
 * 小端模式：数据高位存储高位地址，数据低位存低位地址
 */
#include <stdio.h>
union{
    int n;//4个字节
    char ch;//一个字节
}data;
void main()
{
    data.n = 0x00000001;
    int k=0;
    /**
     * 0x4000 0x4001 0x4002 0x4003
     * 1      0      0      0
     */
    printf("data.n=%#X,data.n=%#X\n",data.n,&data.n);
    printf("data.ch=%#X,data.ch=%#X\n",data.ch,&data.ch);
    printf("k=%#X\n",&k);

}