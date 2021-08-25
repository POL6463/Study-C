#include <stdio.h>

int main(void)
{
    int i;
    auto int sum = 0;

    for (i = 1; i <= 10000; i++)
    {
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}