#include <stdio.h>

int add(int a, int b) { return (a + b); }
int sub(int a, int b) { return (a - b); }
int mul(int a, int b) { return (a * b); }

int main(void)
{
    int (*pary[3])(int, int) = { add, sub, mul};
    int i, res = 0;

    for (i = 0; i < 3; i++)
    {
        res += pary[i](2, 1);
    }

    printf("%d\n", res);

    return 0;
}