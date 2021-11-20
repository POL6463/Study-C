#include <stdio.h>

int main(void)
{
    int ary[5][6] = {
        {1, 2, 3, 4, 5, 0},
        {6, 7, 8, 9, 10, 0},
        {11, 12, 13, 14, 15, 0},
        {16, 17, 18, 19, 20, 0},
        {}
    };
    int sum;

    int i, j, k;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (j == 5)
            {
                sum = 0;
                for (k = 0; k < 5; k++)
                {
                    
                    sum += ary[i][k];
                }
                ary[i][j] = sum;
            }
            
        }

        if (i == 4)
        {
            for (j = 0; j < 6; j++)
            {
                sum = 0;
                for (k = 0; k < 4; k++)
                {
                    sum += ary[k][j];
                }
                ary[i][j] = sum;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%5d", ary[i][j]);
        }
        printf("\n");
    }

    return 0;
}