//
// Created by Administrator on 2019/4/26.


#include <stdlib.h>
#include <stdio.h>

int main()
{

    int *age = (int *)malloc(10* sizeof(int));
    char *az = (char *)malloc(26);

    int n;
//    for(n=0;n<10;n++){
//        age[n] = n;
//    }
//    for(n=0;n< sizeof(age);n++){
//        printf("age[%d]=%d\n",n,age[n]);
//    }
//    int m;
//    for(m=0;m<26;m++){
//        *(az+m)=m;
//    }
//    for(m=0;m<26;m++){
//        printf("m[%d]=%d\n",m,az[m]);
//    }

//    int *height = (int *)calloc(10, sizeof(int));
//    for(n=0;n< sizeof(height);n++){
//        *(height+n) = n;
//    }
//    for(n=0;n< sizeof(height);n++){
//        printf("height[%d]=%d\n",n,*(height+n));
//    }

//    char *name = NULL;
//    char *pname = NULL;
//    pname = realloc(name,10);
//    name = pname;
//    if (name!=NULL){
//        name[0] = 'c';
//    }
//    printf("name[0]=%c\n",*name);
//
//    free(name);

    void *address;

    void *paddress[2];

    address = realloc(address,10);
    return 0;
}
