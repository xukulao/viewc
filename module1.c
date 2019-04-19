//
// Created by Administrator on 2019/4/19.
//
#include <stdio.h>
#include <stdlib.h>
long fSize(FILE *file);

typedef struct stu
{
    char name[50];
    int age;
    int num;
    char address[100];
} STU;
int main()
{
    char *fileName = "E:/c/demo/hello.txt";
    FILE *file;
    if ((file=fopen(fileName,"rb+")) == NULL){
        printf("open file error!");
    }

    STU student = {
            "jack",
            20,
            100,
            "shanghai"
    };

    long size = fSize(file);
    printf("size=%d\n",size);
//    if (size>0){
//        STU student1 = {
//                "jack1",
//                21,
//                101,
//                "beijing"
//        };
//
//        FILE *tmpFILE;
//        char *tmpFileName = "E:/c/demo/hello_tmp.txt";
//        tmpFILE = fopen(tmpFileName,"wb+");
//        int bufferLen = 1024*4;
//        char *buffer = (char *)malloc(bufferLen);
//        int readCount=0;
//        while((readCount=fread(buffer,1,bufferLen,file))>0){
//            fwrite(buffer,readCount,1,tmpFILE);
//        }
//
//        fclose(tmpFILE);
//
//        fseek(file,size,SEEK_SET);
//
//        fwrite(&student1, sizeof(struct stu),1,file);
//
//        size = fSize(file);
//        printf("size=%d\n",size);
//    }

    //STU *stu = &student;
//    fwrite(&student, sizeof(struct stu),1,file);
//    rewind(file);
//
//    STU stuinfo1;
//    STU *stuinfo = &stuinfo1;
//
//
//    fread(stuinfo, sizeof(struct stu),1,file);
//
//
//    printf("%s %d %d %s\n",stuinfo->name,stuinfo->age,stuinfo->num,stuinfo->address);
//

    fclose(file);

    return 0;
}


long fSize(FILE *file)
{
    long position;
    fpos_t fpos;
    fgetpos(file,&fpos);
    fseek(file,0,SEEK_END);
    position = ftell(file);
    fsetpos(file,&fpos);
    return position;
}