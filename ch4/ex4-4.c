#include <stdio.h>

int main(void)
{
    int a = 5, b = 5;
    int pre, post;

    pre = (++a) * 3;
    post = (b++) * 3;

    printf("초깃값 a = %d, b = %d\n", a, b);
    printf("전위형: (++a) * 3 = %d\n후위형: (b++) * 3 = %d\n", pre, post);

    return 0;
}