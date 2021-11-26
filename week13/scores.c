#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *pi, n, i, total = 0, max, min; //각종 변수 선언

    printf("학생수: ");
    scanf("%d", &n); //학생수 입력받음

    pi = (int *)malloc(sizeof(int) * n); //학생수만큼 int 공간 할당

    for(i = 0; i < n; i++){ //학생수만큼 점수 입력받음
        printf("점수 입력: ");
        scanf("%d", pi + i);
    }

    max = pi[0]; //최대값, 최솟값 초기화
    min = pi[0];
    printf("%d \n", min);

    for(i = 0; i < n; i++){ //총합, 최대, 최소 알아내는 부분
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