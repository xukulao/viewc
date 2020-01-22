//
// Created by Administrator on 2016/4/18.
//

#include <stdio.h>
typedef unsigned int UINT;
typedef unsigned char UCHAR;
typedef char *STRING;
typedef UINT ARRAY[20];

typedef struct bit{
    UINT led:1;
} SBIT;

typedef struct car{
    STRING name;
    float money;
}CAR[2];

typedef struct person{
    STRING name;
    UINT age;
    UINT height;
    STRING address;
    STRING love[5];
    CAR cars;
} *PERSON[];
int main()
{

    UINT a = 100;
    UCHAR b = 'c';
    STRING name = "chinese";
    ARRAY age = {1};
    SBIT ledOn;
    ledOn.led = 1;

    printf("a=%d,b=%c,name=%s,age=%d,led=%#X\n",a,b,name,age[0],ledOn.led);

    struct person jack = {"jack",10,180,"japanese",{"walk","watching","talking"},{
            {"Baoma",60},
            {"Luhu",100}
    }};
    struct person tony =  {"lucy",20,160,"shanghai",{"speaking","football","pc game"},{
            {"Falali",100},
            {"Benchi",800}
    }};
    PERSON students = {&jack,&tony};

    printf("%s 's age is %d,his height is %d,where is %s,his love is %s\n",students[0]->name,
            students[0]->age,students[0]->height,students[0]->address,students[0]->love[0]);

    int i=0;
    printf("Name\t\tAge\t\tHeight\t\tAddress\t\tLove\t\t\t\t\tCars\n");
    for(i;i<2;i++){

        printf("%s\t\t%d\t\t%d\t\t%s\t",students[i]->name,students[i]->age,students[i]->height,students[i]->address);
        int k=0;
        for(k;k<3;k++){
            printf("%s/",students[i]->love[k]);
        }

        printf("\t\t%s/%d",students[i]->cars->name,students[i]->cars->money);
        printf("\n");
    }

    struct car baoma = {"baoma",100};
    struct car luhu = {"luhu",500};
    CAR cars = {baoma,luhu};
    printf("%s = %f\n",cars[0].name,cars[0].money);
    return 0;
}
