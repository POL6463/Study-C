#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *pi, n, i, total = 0, max, min;

    printf("학생수: ");
    scanf("%d", &n);

    pi = (int *)malloc(sizeof(int) * n);

    for(i = 0; i < n; i++){
        printf("점수 입력: ");
        scanf("%d", pi + i);
    }

    max = pi[0];
    min = pi[0];
    printf("%d \n", min);

    for(i = 0; i < n; i++){
        total += pi[i];
        if(max < pi[i]){
            max = pi[i];
        }
        if(min > pi[i]){
            min = pi[i];
        }
    }

    printf("총점: %d , 평균: %.1lf , 최고점: %d , 최저점 %d", total, total/(double)n, max, min);

    return 0;
}