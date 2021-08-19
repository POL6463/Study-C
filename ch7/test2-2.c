#include <stdio.h>

void sum(int x);

int main(void)
{
    sum(10);
    sum(100);
    return 0;
}

void sum(int x)
{
    int count;
    int res;
    for (count = 1; count <= x; count++)
    {
        
        res += count;
        printf("count : %d, res : %d\n", count, res);
    }
    printf("1부터 %d까지의 합은 %d 입니다.\n", x, res);
    res = 0;
}