#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[15];
    char str2[15];
    int i;

    printf("단어 입력 : ");
    scanf("%s", str1);
    strncpy(str2, str1, 5);
    for (i = strlen(str2); i < strlen(str1); i++)
    {
        str2[i] = '*';
    }
    printf("입력한 단어 : %s, 생략한 단어 : %s\n", str1, str2);

    return 0;
}