#include <stdio.h>

int main(void)
{
    int a = 10;
    int *pi;
    int **ppi;

    pi = &a;
    ppi = &pi;

    printf("-----------------------------------\n");
    printf("변수    변수값    &연산    *연산    **연산\n");
    printf("-----------------------------------\n");
    printf("  a%15d%15u\n", a, &a);
    printf(" pi%15u%15u%15d\n", pi, &pi, *pi);
    printf("PPI%15u%15u%15u%15u\n", ppi, &ppi, *ppi, **ppi);
    printf("-----------------------------------\n");
    return 0;
}