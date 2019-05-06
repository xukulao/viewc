//
// Created by 1655664358@qq.com on 2019/5/6.
//
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "tool.h"

long getFileSize(FILE *file)
{
    long fsize;
    fpos_t fpos;
    fgetpos(file,&fpos);
    fseek(file,0,SEEK_END);
    fsize = ftell(file);
    fsetpos(file,&fpos);
    return fsize;
}
void pause(const char *str,...)
{
    va_list ap;
    char buffer[50];
    va_start(ap,str);
    vsnprintf(buffer,500,str,ap);
    va_end(ap);
    printf(buffer);
    getch();
    printf("\n");
}
