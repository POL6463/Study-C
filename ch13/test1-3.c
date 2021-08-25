#include <stdio.h>

int func(void);

int main(void)
{
    int i, sum = 0;

    for (i = 0; i < 10; i++)
    {
        sum += func();
    }

    printf("%d\n", sum);
    return 0;
}

int func(void)
{
    static int a;
    a++;
    return a;
}