#include <stdio.h>

void input_data(int *pa, int *pb);
void swap_data(void);
void print_data(int a, int b);

int a, b;

int main(void)
{
    input_data(&a, &b);
    swap_data();
    print_data(a, b);

    return 0;
}

void input_data(int *pa, int *pb)
{
    printf("두 정수 입력 : ");
    scanf("%d%d", pa, pb);
}

void swap_data(void)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void print_data(int a, int b)
{
    printf("두 정수 출력 : %d, %d\n", a, b);
}