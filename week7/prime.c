#include <stdio.h>

int main(void){
    int i, j, num;
    int count;

    printf("2 이상의 정수: ");
    scanf("%d", &num);

    for(i = 2; i <= num; i++){

        for(j = 2; j <= i; j++){
            if(i == j){
                printf("%d ", i);
                count++;
                if(count % 5 == 0){
                printf("\n");
                }
            }
            else if(i % j == 0){
                break;
            }
        }

        
    }

    return 0;
}