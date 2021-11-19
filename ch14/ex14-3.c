#include <stdio.h>
#include <string.h>

int main(void)
{
    char animal[5][80];
    int i;
    int count;
    int used = 0;

    count = sizeof(animal)/ sizeof(animal[0]);
    for (i = 0; i < count; i++)
    {
        gets(animal[i]);
        used += (strlen(animal[i]) + 1);
    }

    for (i = 0; i < count; i++)
    {
        printf("%s\n", animal[i]);
    }

    printf("전체 바이트: %lu, 사용된 바이트: %d, 사용 비율: %.2lf%%\n", sizeof(animal), used, (double)used/400 * 100);



    return 0;
}