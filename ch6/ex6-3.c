#include <stdio.h>

int main(void)
{
    int a = 1;

    do
    {
        a = a * 2;
        printf("a : %d\n", a);
    } while (a < 10);
    printf("a : %d\n", a);

    return 0;    
}