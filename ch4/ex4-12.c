#include <stdio.h>

int main(void)
{
    int a = 10, b = 20, res;

    res = (a > b) ? a : b;
    printf("큰 값 : %d\n", res);

    return 0;
}