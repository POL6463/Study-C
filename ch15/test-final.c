#include <stdio.h>
#include <string.h>

void swap(char *cp, void *a, void *b)
{
    int temp_int;
    double temp_db;

    if (strcmp(cp, "int") == 0)
    {
        temp_int = *(int *)a;
        *(int *)a = *(int *)b;
        *(int *)b = temp_int;
    }

    if (strcmp(cp, "double") == 0)
    {
        temp_db = *(double *)a;
        *(double *)a = *(double *)b;
        *(double *)b = temp_db;
    }
}

int main(void)
{
    int a1, b1;
    double a2, b2;

    printf("첫 번째 사람의 나이와 키 입력 : ");
    scanf("%d%lf", &a1, &a2);
    printf("두 번째 사람의 나이와 키 입력 : ");
    scanf("%d%lf", &b1, &b2);

    swap("int", &a1, &b1 );
    swap("double", &a2, &b2);

    printf("첫 번째 사람의 나이와 키 : %d, %.1lf\n두 번째 사람의 나이와 키 : %d, %.1lf\n", a1, a2, b1, b2);

    return 0;
}