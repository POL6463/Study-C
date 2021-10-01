#include <stdio.h>

int main(void) {
    int year;
    printf("년도 : ");
    scanf("%d", &year);

    if((year % 1000) == 0){
        printf("윤년\n");
    }
    else if((year % 100) == 0){
        printf("평년\n");
    }
    else if((year % 4) == 0){
        printf("윤년\n");
    }
    else {
        printf("평년\n");
    }
}