#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    struct student{
        char name[20];
        double grade;
    };

    struct student list[5] = {0};
    int i;
    
    

    for(i = 0; i < 3; i++){
        printf("name: ");
        gets(list[i].name);
        printf("grade: ");
        scanf("%lf", &list[i].grade);
        fflush(stdin);
    }

    for(i = 0; i < 3; i++){
        printf("%s, %.1lf\n", list[i].name, list[i].grade);

    }

    return 0;

    
}