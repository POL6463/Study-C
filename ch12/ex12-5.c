#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80];
    printf("공백이 포함된 문자열 입력 : ");
    fgets(str, sizeof(str), stdin);
    
    str[strlen(str) - 1] = '\0';
    printf("입력된 문자열은 %s입니다\n", str);
    return 0;
}