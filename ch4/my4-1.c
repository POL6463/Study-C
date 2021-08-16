#include <stdio.h>

int main(void)
{
    int a, b;
    int sum, sub, mul, inv;



    printf("a의 값 : , b의 값 : \n");
    scanf("%d%d", &a, &b);

    sum = a + b;
    sub = a - b;
    mul = a * b;
    inv = -a;

    printf("덧셈 : %d\n", sum);
    printf("뺄셈 : %d\n", sub);
    printf("곱셈 : %d\n", mul);
    printf("a의 음수 연산 : %d\n", inv);

    return 0;
}