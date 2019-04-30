//
// Created by 1655664358@qq.com on 2019/4/30.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct person{
    char name[100];
    int age;
    int num;
}person;
int main()
{

    char fileName[100] = "E:/c/demo/module/person.txt";

    char *name = (char *)calloc(100, sizeof(char));

    FILE *file = fopen(fileName,"rb+");

    //fread(name, sizeof(struct person),file);
    //printf("please type your name\n");
    //scanf("%s",name);
    //scanf("%s",name);
    //fwrite(name,10,1,file);
    fread(name,10,1,file); 
    printf("name=%s\n",name);
    free(name);
    fclose(file);
//    int *address = (int *)malloc(10*sizeof(int));
//    //address = (int *)malloc(10*sizeof(int));
//    if (address==NULL)exit(0);
//    //address = "sss1234567";
//    int i;
//    for(i=0;i<10;i++){
//        address[i] = i;
//    }
//    printf("address[0]=%d\n",*(address+1));
//    free(address);
//
//    char *city = (char *)calloc(10, sizeof(char));
//    //city = "chinese";//内存丢失了，上面的语句导致内存丢失，内存地址不知道关联哪个符号了，导致程序异常
//    city[0] = 'c';
//    printf("city=%c\n",*city);
//    free(city);

//    FILE *file = fopen(fileName,"rb+");
//    fwrite(name,10,1,file);
//    fclose(file);
//    free(name);



//    FILE *file = fopen(fileName,"rb+");
//    person tony;
//
//    scanf("%s %d %d",tony.name,&tony.age,&tony.num);
//    person per;
//    if(file!=NULL){
//
//        //fread(&tony, sizeof(struct person),1,file);
//        fwrite(&tony, sizeof(struct person),1,file);
//
//        //fread(&per, sizeof(struct person),1,file);
//    }
//
//
//    printf("%d\n",per.age);
//
//    fclose(file);
//
//    FILE *read;
//    read = fopen(fileName,"rb+");
//    fread(&per, sizeof(struct person),1,read);
//    printf("%s\n",per.name);
//    fclose(read);

    return 0;
}
