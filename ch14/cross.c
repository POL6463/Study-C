#include <stdio.h>

int main(void)
{
    char mark[5][5];
    char mark1[5][5];
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == j)
            {
                mark[i][j] = 'X';
            }
            else
            {
                mark[i][j] = ' ';
            }
            
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == j)
            {
                mark1[i][j] = 'X';
            }
            else if((i + j) == 4)
            {
                mark1[i][j] = 'X';
            }
            else
            {
                mark1[i][j] = ' ';
            }
            
            
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", mark[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", mark1[i][j]);
        }
        printf("\n");
    }

    return 0;
}