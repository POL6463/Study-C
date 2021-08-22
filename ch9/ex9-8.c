#include <stdio.h>

void swap(void);

int main(void)
{
    int a = 10, b = 20;

    swap();
    printf("a:%d, b:%d\n", a, b);

    return 0;
}

void swap(void)
{
    int temp;

    temp =a;
    a = b;
    b = temp;
}
// 이렇게 하면은 컴파일 오류가 난다.
//swap 함수 안에서 a, b 가 정의되어있지 않아서