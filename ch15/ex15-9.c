#include <stdio.h>

int main(void)
{
    int a = 10;
    double b = 3.5;
    void *vp;

    vp = &a;
    printf("a : %d\n", *(int *)vp);

    vp = &b;
    printf("b : %.1f\n", *(double *)vp);

    return 0;
}