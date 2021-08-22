#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 12;

    //비트별 논리곱 연산자, 모두 1인경우에만 1
    printf("a & b : %d\n", a & b);

    //비트별 배타적 논리합 연산자, 서로 다른겨우에만 1
    printf("a ^ b : %d\n", a ^ b);

    //비트별 논리합 연산자, 하나라도 참이면 1
    printf("a | b : %d\n", a | b);

    //비트별 부정 연산자, 반대로 바꿈
    printf("~a : %d\n", ~a);

    //비트 이동 연산자, 왼쪽으로 이동
    printf("a << 1 : %d\n", a << 1);

    //비트 이동, 오른쪽으로
    printf("a >> 2 : %d\n", a >> 2);

    return 0;
}