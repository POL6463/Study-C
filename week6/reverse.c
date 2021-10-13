#include <stdio.h>

int main(void){
    int a[] = {1, 3, 5, 23, 6, 9, 10, 7, 9};
    int temp, i;

    int count = sizeof(a)/sizeof(a[0]);

    for(i = 0; i < count/2; i++){
        temp = a[i];
        a[i] = a[count-1 - i];
        a[count -1 -i] = temp;
    }

    for(i = 0; i < count; i++){
        printf("%d  ", a[i]);
    }

    return 0;
}