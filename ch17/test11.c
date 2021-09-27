#include <stdio.h>

int n, m, max, min, i, num1, num2;


void swap(int* i, int* j) {
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

int maxi(int arr[], int max, int index) {
    int i;
    for (i = 1; i < index; i++)
        if (max < arr[i])
            max = arr[i];
    return (max);
}

int mini(int arr[], int max, int index) {
        int i;
        for (i = 1; i < index; i++)
            if (min > arr[i])
                min = arr[i];
        return (min);
}

int main(void){

    int index1 = 1, index2 = 1;
    int large[100], small[100];


    printf("Give n : \n");
    scanf(" %d", &n);
    printf("n = %d \n", n);

    /* Initialize Max and Min */
    scanf(" %d", &max);
    min = max;
    m = n - 1;

    if (n % 2 == 0) {
        scanf(" %d", &min);
        if (max < min)
            swap(&max, &min);
        m = m - 1;
    }

    /* Fill up the arrays large & small */
    for (i = 1; i <= m / 2; i++) {
        scanf(" %d %d", &num1, &num2);
        if (num1 >= num2) {
            large[index1++] = num1;
            small[index2++] = num2;
        }
        else {
            large[index1++] = num2;
            small[index2++] = num1;
        }
    }

    max = maxi(large, max, index1);
    min = mini(small, min, index2);

    printf("Max = %d, Min = %d", max, min);
    
    return 0;
}