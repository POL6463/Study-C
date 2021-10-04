#include <stdio.h>

int lcm(int, int);

int main(void){
    int a, b, l;
    printf("Enter any two positive integers ");
    scanf("%d%d", &a, &b);

    if(a>b){
        l = lcm(a,b);
    }
    else{
        l = lcm(b,a);
    }

    printf("LCM of two integers is %d", l);

    return 0;
}

int lcm(int a, int b){
    static int c = 0;
    c += b;
    
    if(c%a == 0){
        return c;
    }
    else{
        return lcm(a, b);
    }
}