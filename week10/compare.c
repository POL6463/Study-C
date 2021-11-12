#include <stdio.h>
#include <string.h>

int main(void){
    char first[100];
    char second[100];

    printf("첫번째 문자를 입력하세요: ");
    scanf("%s", first);
    printf("두번째 단어를 입력하세요: ");
    scanf("%s", second);

    if(strlen(first) > strlen(second)){
        printf("길이순: %s\n", first);
    }
    else if(strlen(second)> strlen(first)){
        printf("길이순: %s\n", second);
    }
    else{
        printf("두 단어의 길이가 같습니다.\n");
    }

    if(strcmp(first, second) > 0){
        printf("알파벳순: %s\n", first);
    }
    else if(strcmp(first, second) < 0){
        printf("알파벳순: %s\n", second);
    }
    else{
        printf("두 단어가 같습니다.\n");
    }

    return 0;
}