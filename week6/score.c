#include <stdio.h>

int main(void){
    int score[5];
    int i;

    for(i = 0; i < 5; i++){
        printf("input: ");
        scanf("%d", &score[i]);
    }

    int total = 0;
    for(i = 0; i < 5; i++){
        total += score[i];
    }
    
    printf("총합: %d, 평균: %.1lf", total, total/5.0);

    return 0;
}