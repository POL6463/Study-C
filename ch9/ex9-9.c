#include <stdio.h>

void swap(int x, int y);

int main(void)
{
    int a = 10, b = 20;

    swap(a, b);
    printf("a:%d, b:%d\n", a, b);

    return 0;
}

void swap(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = x;
}
// 바뀌지 않는다, 함수가 다르면 메모리에 별도의 저장 공간을 확보하므로.