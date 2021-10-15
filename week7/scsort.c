#include <stdio.h>

int main(void){
    int score[5];
    int sort[5] = {0,};

    int i, j, temp, total =0;

    for(i = 0; i < 5; i++){
        printf("input: ");
        scanf("%d", &score[i]);
    }

    for(i = 0; i < 5; i++){
        sort[i] = score[i];
        total += score[i];
    }

    for(i = 0; i < 5; i++){
        for(j = i; j < 5; j++){
            if(sort[i] < sort[j]){
                temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }

    printf("내림차순\n");
    for(i = 0; i < 5; i++){
        printf("%d ", sort[i]);
    }
    printf("\n");
    printf("총합: %d, 평균: %.1lf\n", total, total/5.0);

    return 0;
}