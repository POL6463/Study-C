#include <stdio.h>

int main(void)
{
    int age;
    double height;

    printf("나이와 키를 입력하시오 : ");
    scanf("%d%lf", &age, &height);
    printf("나이는 %d 살, 키는 %.1lf cm입니다\n", age, height);

    return 0;
}