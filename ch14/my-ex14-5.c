#include <stdio.h>

int main(void)
{
    int score[2][3][4];

    int i, j, k;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d반 %d번 학생의 4과목 점수 입력 : ", i + 1, j + 1);
            for (k = 0; k < 4; k++)
            {
                
                scanf("%d", &score[i][j][k]);
            }
        }
    }

    for (i = 0; i < 2; i++)
    {
        printf("%d반 점수...\n", i + 1);
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                printf("%5d", score[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}