#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;

    printf("교환 전 a와 b의 값 : %d, %d\n", a, b);
    {
        int temp;

        temp = a;
        a = b;
        b = temp;
    }
    printf("교환 후 a와 b의 값 : %d, %d\n", a, b);

    return 0;
}