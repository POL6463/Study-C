#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Be happy~\n");
            if (j == 2) break;
        }
    }
    return 0;
}