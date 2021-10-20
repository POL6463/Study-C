#include <stdio.h>

struct Album
{
    char genre[50];
    int play;
};


int main(void){
    struct Album album[10005];
    int num, i;

    scanf("%d", &num);

    for(i = 0; i < num; i++){
        scanf("%s%d", album[i].genre, &album[i].play);
    }

    printf("%s, %d", album[0].genre, album[0].play);

    return 0;
    
}