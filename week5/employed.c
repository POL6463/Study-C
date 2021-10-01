#include <stdio.h>

int main(void) {
    int grad;
    int emp;
    double rate;

    printf("졸업생수 : ");
    scanf("%d", &grad);

    printf("취업자수 : ");
    scanf("%d", &emp);

    rate = (double)emp / (double)grad;

    printf("취업율: %.1lf", rate * 100);

    return 0;
}