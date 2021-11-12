#include <stdio.h>
#include <string.h>

int main(void){
    char letter[100] = {0};
    int i;
    int len;

    printf("input: ");
    fgets(letter, sizeof(letter), stdin);

    len = strlen(letter);

    for(i = 0; i < len; i++){
        if((letter[i] >= 'A') && (letter[i] <= 'Z')){
            letter[i] = letter[i] + 32;
        }
    }

    printf("%s", letter);

    return 0;
}