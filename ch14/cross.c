#include <stdio.h>

int main(void)
{
    char mark[5][5] = {0};
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if(i == j || (i+j)==4)
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
            printf("%c ", mark[i][j]);
        }
        printf("\n");
    }


    return 0;
}