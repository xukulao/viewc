//
// Created by Administrator on 2019/4/26.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count,n,input;
    count =0;
    int *numbers = NULL;
    int *more_numbers = NULL;

    do{
        printf("please enter the num:\n");
        scanf("%d",&input);
        count++;
        more_numbers = realloc(numbers,count*sizeof(int));
        if (more_numbers!=NULL){
            numbers = more_numbers;
            numbers[count-1] = input;
        }else{
            free(numbers);
            puts("error");
            exit(1);
        }
    }while(input!=0);

    printf("the result\n");
    for(n=0;n<count;n++){
        printf("numbers[%d]=%d\n",n,*(numbers+n));
    }

    free(numbers);
    return 0;
}