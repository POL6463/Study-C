#include <stdio.h>

void hanoi_tower(int n, char from, char temp, char to){
    
    if(n==1) printf("원판 1을 %c 에서 %c 으로 옯긴다.\n", from, to);
    else{
        hanoi_tower(n-1, from, to, temp);
        printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
        hanoi_tower(n-1, temp, from, to);
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    hanoi_tower(n, 'A', 'B', 'C');
    return 0;
}