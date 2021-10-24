#include <stdio.h>

void isPrime(int);


int main(void){
    int num;

    printf("2 이상의 정수: ");
    scanf("%d", &num);

    isPrime(num);

    return 0;
}

void isPrime(int num){
    int i, j;
    int count;
    

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
}