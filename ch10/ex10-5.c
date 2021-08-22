#include <stdio.h>

void print_ary(int *pa);

int main(void)
{
    int ary[5] = { 10, 20, 30, 40, 50};

    print_ary(ary);

    return 0;
}

void print_ary(int *pa)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%d ", pa[i]);
    }
}