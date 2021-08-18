#include <stdio.h>

int main(void)
{
    int i;
    int j;
    int start;
    int counter;
    printf("2 이상의 정수를 입력하세요 : ");
    scanf("%d", &i);

    for (start = 2; start <= i; start++)
    {
        for (j = 2; j <= start; j++)
        {
            if (j == start)
            {
                printf("%d", start);
                printf("  ");
                counter++;
                if (counter % 5 == 0)
                {
                    printf("\n");
                }
                
            }
            else if (start % j == 0)
            {
                break;
            }
            
        }
    }

    return 0;
}