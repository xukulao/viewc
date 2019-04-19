//
// Created by Administrator on 2019/4/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char name[50];
    int age;
    int num;
    char address[100];
} PERSON;

long insert(FILE *file,PERSON person,long offset);
long fSize(FILE *file);
int getMenuid();
void removeUser();
int main()
{

    FILE *file;
    char *fileName = "E:/c/viewc/persondata.txt";
    file = fopen(fileName,"rb+");
    if (file == NULL){
        printf("error!");
    }
    int menuid;
    PERSON person;

    PERSON *per = &person;
    PERSON tempPerson;

    PERSON *tmp = &tempPerson;

    char *tempName = NULL;
    char *yesNo = NULL;
    int readCount = 0;
    while (1){
        menuid = getMenuid();
        fseek(file,0,SEEK_SET);
        switch(menuid){
//            case 0:
//                printf("nothing\n");
//                break;
            case 1:
                printf("please enter person info!\n");
                scanf("%s %d %d %s",per->name,&per->age,&per->num,per->address);

                insert(file,*per,0);
                break;
            case 2:
                //fread(&tempPerson, sizeof(struct person),1,file);
                //printf("%s %d %d %s\n",tmp->name,tmp->age,tmp->num,tmp->address);
                printf("Name\t\tAge\t\tNum\t\tAddress\n");
                while((readCount=fread(tmp, sizeof(struct person),1,file))>0){
                    printf("%s\t\t%d\t\t%d\t\t%s\n",tmp->name,tmp->age,tmp->num,tmp->address);
                }
                fseek(file,0,SEEK_SET);
                break;
            case 3:
                removeUser(file);
                break;
            default:


                break;
        }
    }
    fclose(file);
    return 0;
}


int getMenuid()
{
    int menuid;
    printf("***************************************************\n");
    printf("[1]:add person\n");
    printf("[2]:list person\n");
    printf("[3]:remove person\n");
    printf("***************************************************\n");
    scanf("%d",&menuid);
    fflush(stdin);
    return menuid;
}



long insert(FILE *file,PERSON person,long offset)
{
    long Size = fSize(file);
    fseek(file,Size,SEEK_SET);
    fwrite(&person, sizeof(struct person),1,file);
    fseek(file,0,SEEK_SET);

}

long fSize(FILE *file)
{
    long n;
    fpos_t fpos;
    fgetpos(file,&fpos);
    fseek(file,0,SEEK_END);
    n = ftell(file);
    fsetpos(file,&fpos);
    return n;
}

void removeUser(FILE *file)
{
    printf("input username who u want to remove\n");
    char temp[50];
    fflush(stdin);
    scanf("%s",temp);

    PERSON tempPerson;

    PERSON *tmp = &tempPerson;

    int readCount=0;
    int nBytes = 0;
    if(temp){

        fseek(file,0,SEEK_SET);
        FILE *tmpfile;
        char tmpfileName[50] = "E:/c/viewc/persond_temp.txt";
        tmpfile = fopen(tmpfileName,"wb+");
        fseek(tmpfile,0,SEEK_SET);
        while((readCount=fread(tmp, sizeof(struct person),1,file))>0){
            nBytes+=readCount;
            if (tmp&&strcmp(temp,tmp->name) != 0){
                fwrite(tmp,sizeof(struct person),1,tmpfile);
            }
        }
        fseek(tmpfile,0,SEEK_SET);

        fclose(tmpfile);

        //读取临时文件复制到原来的文件完成删除功能
        tmpfile = fopen(tmpfileName,"rb+");
        file = fopen("E:/c/viewc/persondata.txt","wb+");

        fseek(file,0,SEEK_SET);
        PERSON *tmp = &tempPerson;
        while((readCount=fread(tmp, sizeof(struct person),1,tmpfile))>0){
            printf("copy %s\n",tmp->name);
            fwrite(tmp,sizeof(struct person),1,file);
        }
        fclose(tmpfile);
        fseek(file,0,SEEK_SET);
    }


}