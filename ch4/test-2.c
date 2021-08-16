#include <stdio.h>

int main(void)
{
    int a, b, tot;
    double avg;

    printf("두 과목의 점수 : ");
    scanf("%d%d", &a, &b);
    tot = a + b;
    avg = tot / 2.0;

    printf("평균 : %.1lf\n", avg);

    return 0;
}