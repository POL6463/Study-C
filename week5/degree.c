#include <stdio.h>

int main(void) {
    double C;
    double F;

    printf("섭씨 온도를 입력하세요 : ");
    scanf("%lf", &C);

    F = C * 1.8000 + 32.00;

    printf("화씨 온도 : %.3lf", F);

    return 0;
}