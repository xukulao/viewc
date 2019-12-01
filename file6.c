//
// Created by Administrator on 2016/4/18.
//

#include <stdio.h>
#define N 10
int main()
{
    char *a[N],*b[N];
    int size = sizeof(char);
    FILE *file;
    char *fileName = "E:/c/demo/hello.txt";
    file = fopen(fileName,"rb+");
    if(file == NULL){
        printf("file not found!");
    }

    int i;
    for(i=0;i<N;i++){
        scanf("%s",&a[i]);
    }

    fwrite(a,size,N,file);

    rewind(file);

    fread(b,size,N,file);

    for(i=0;i<N;i++){
        printf("%s",b[i]);
    };

    printf("\n");

    return 0;
}
