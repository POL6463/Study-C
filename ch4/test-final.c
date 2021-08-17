#include <stdio.h>

int main(void)
{
    int kg;
    double cm, BMI;
    double m;

    printf("몸무계(kg)와 키(cm) 입력 : ");
    scanf("%d%lf", &kg, &cm);
    m = cm * 0.01;

    BMI = kg / (m * m);


    printf("%s, %lf, %lf, %lf, %d\n", ((BMI > 20 && BMI < 25) ? "표준입니다" : "체중관리가 필요합니다."), BMI, cm, m, kg);
    
    return 0;

}