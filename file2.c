//
// Created by Administrator on 2019/4/18.
//

#include <stdio.h>
#include <string.h>
int main()
{
    //char *fileName = "E:/c/demo/hello.txt";
    char *fileName = "E:/c/demo/hello.php";
    FILE *file = fopen(fileName,"rt");

    if (file == NULL){
        printf("Error:not found file!");
    }

    char ch;
    while((ch=fgetc(file))!=EOF){
        putchar(ch);
    }

    putchar('\n');



//    fclose(file);
//    char cmd[100] = "php ";
//    char *content = system(strcat(cmd,fileName));
//
//    printf("%s\n",*content);

    if(ferror(file)){
        printf("read error!");
    }else{
        printf("read success!");
    }
    return 0;
}