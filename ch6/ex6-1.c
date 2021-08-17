#include <stdio.h>

int main(void)
{
    int a = 1;

    while (a < 10)
    {
        a = a * 2;
        printf("a : %d\n", a);

    }
    printf("a : %d\n", a);

    return 0;
}