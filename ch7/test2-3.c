#include <stdio.h>

int func(int n);
int poly(int n);

int main(void)
{
    printf("%d\n", func(-3));
    return 0;
}

int func(int n)
{
    int res;
    res = poly(n);
    if (res >= 0) return res;
    else
    {
        return -res;
    }
}    

int poly(int n)
{
    return((2 * n * n) + (3 * n));
}
