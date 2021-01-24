//
// Created by 1655664358@qq.com on 2015/5/20.
//
#include <stdio.h>
typedef int function;
#define echo(text) printf(text);
#define ECHO(text) printf(text);
#define 主程序 int main(){
#define 结束 }
#define 格式化打印 printf
#define 输出一行 put
function talk();



function main()
{
    echo("I'm the best language in the world!")
    talk();
    return 0;
}

function talk()
{
    ECHO("nihao")
    return 0;
}


//int main()
//{
//    data.n = 0x20000001;
//    /**
//     * 数据0x00 高位
//     * 数据0x01 低位
//     *
//     * 内存地址 从低到高
//     * 小端模式：数据低位保存在低位地址，数据高位保存在高位地址
//     */
//
//    printf("k=%d,k=%#X\n",k,&k);
//    printf("data=%#X,data of address=%#X\n",data,&data);
//    printf("data.n=%#X,data.n=%#X\n",data.n,&data.n);
//
//    printf("data.ch=%#X,data.ch=%#X\n",data.ch,&data.ch);
//    printf("m=%d,m=%#X\n",m,&m);
//    return 0;
//}
