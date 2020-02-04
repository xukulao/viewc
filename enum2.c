//
// Created by Administrator on 2016/4/1.
//

#include <stdio.h>

int main()
{
    //enum week {MON=1,TUES,WEDNES,THUR,FRI,SAT,SUN,NOTHING="CHINA"};不支持
    enum week {MON=1,TUES,WEDNES,THUR,FRI,SAT,SUN,NOTHING=0};
    enum week day;
    enum week d = MON;
    enum week d1 = 200;
    //NOTHING = 100;  不支
    enum week d2 = NOTHING;

    //enum week d2 = "china";//枚举变量不支持字符串

    printf("%d,%d\n",d,d1);
    //printf("%s\n",d2);

    printf("d2=%d,enum week=%d\n", sizeof(d2), sizeof(enum week));
    scanf("%d",&day);
    switch(day){
        case MON:
            printf("%s\n","monday");
            break;
        case TUES:
            printf("%s\n","thesday");
            break;
        case WEDNES:
            printf("%s\n","wednesday");
            break;
        case THUR:
            printf("%s\n","thurday");
            break;
        case FRI:
            printf("%s\n","friday");
            break;
        case SAT:
            printf("%s\n","saturday");
            break;
        case SUN:
            printf("%s\n","sunday");
            break;
        case NOTHING:
            printf("%d,d2=%d\n",NOTHING,d2);
            break;
    }
    return 0;
}
