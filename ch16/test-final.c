#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ary;
    int i, j, n;
    int is_prime;
    

    printf("양수 입력 : ");
    scanf("%d", &n);
    ary = (int *)malloc(n - 2);
    for(i = 0; i < n-2; i++)
    {
        ary[i] = (i + 2);
    }

    for (i = 0; i < n-2; i++)
    {
        is_prime = 0;
        for (j = 0; j < i; j++)
        {
            if(ary[i] % (j+2) == 0)
            {
                is_prime = 1;
                break;
            }
            
        }

        if(is_prime == 1)
        {
            printf("%5c  ", 'X' );
        }
        else
        {
            printf("%5d  ", ary[i]);
        }

        if ((i - 4) % 5 == 0)
        {
            printf("\n");
        }
    }

    return 0;
}