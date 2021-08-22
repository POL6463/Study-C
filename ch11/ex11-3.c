#include <stdio.h>

int main(void)
{
    int ch;

    ch = getchar();
    printf("입력한 문자 : ");
    putchar(ch);
    putchar('\n');

    return 0;
}