#include <stdio.h>

int main(void)
{
    int kor = 3, eng = 5, mat = 4, credits, res;
    double kscore = 3.8, escore = 4.4, mscore = 3.9, grade;

    credits = kor + eng + mat;
    grade = (kscore + escore + mscore) / 3.0;
    res = (credits >= 10) && (grade > 4.0);

    printf("평균 학점 : %lf, 결과 : %d\n", grade, res);

    return 0;
}