//
// Created by Administrator on 2019/4/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char *str = (char *)calloc(10, sizeof(char));
    strcpy(str,"I am chinese man");
    puts(str);
    free(str);
     free(str);
    if (str){
        puts(str);
    }
    return 0;
}
