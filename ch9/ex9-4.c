#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    const int *pa = &a;
    // const = pa가 가리키는 변수 a는 pa를 간접참조하여 바꿀 수 없음 *pa = 20 같이.

    printf("변수 a 값 : %d\n", *pa);
    pa = &b;
    printf("변수 b 값 : %d\n", *pa);
    pa = &a;
    a = 20;
    printf("변수 a 값 : %d\n", *pa);

    return 0;
}