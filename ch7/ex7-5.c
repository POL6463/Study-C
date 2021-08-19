#include <stdio.h>

//재귀함수

void fruit(int count);

int main(void)
{
    fruit(1);

    return 0;
}

void fruit(int count)
{
    printf("apple\n");
    if (count == 3) return;
    fruit(count + 1);
}