#include <stdio.h>

int main(void)
{
    int a;
    double b;
    char c;

    printf("int형 변수 주소 : %u\n", &a);
    printf("double형 변수 주소 : %u\n", &b);
    printf("char형 변수 주소 : %u\n", &c);

    return 0;
}