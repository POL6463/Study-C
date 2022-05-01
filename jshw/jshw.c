#include <stdio.h>
#include <time.h>


long long int dc_sum(long long int);
long long int for_sum(long long int);
long long int dc_odd_sum(long long int);
long long int dc_even_sum(long long int);
long long int for_odd_sum(long long int);
long long int for_even_sum(long long int);


int main() {
    clock_t start, end, result;
    int i,t;
    long long int num;
    int select;


    printf("숫자 n까지 합할 n을 입력해주세요 : ");
    scanf("%lld", &num);
    printf("실행 할 연산의 종류를 고르세요\n");
    printf("1. 전체 합 \n2. 홀수 합 \n3. 짝수 합\n");
    scanf("%d", &select);

    if(select == 1){
        printf("순차적 계산 시작!\n");
        start = clock();
        for(int i = 0; i < 7; i++){
            printf("계산 값: %lld\n", for_sum(num));
        }
        end = clock();
        result = end - start;
        printf("순차적 계산 시간 측정 결과 : %lu ms\n", result);

        start = clock();
        printf("분할 정복 계산 시작\n");
        for(int i = 0; i < 7; i++){
            printf("계산 값: %lld\n", dc_sum(num));
        }
        end = clock();
        result = end - start;
        printf("분할 정복 계산 시간 측정 결과 : %lu ms\n", result);

    }else if (select == 2)
    {
        printf("순차적 계산 시작!\n");
        start = clock();
        for(int i = 0; i < 7; i++){
            printf("계산 값: %lld\n", for_odd_sum(num));
        }
        end = clock();
        result = end - start;
        printf("순차적 계산 시간 측정 결과 : %lu ms\n", result);

        start = clock();
        printf("분할 정복 계산 시작\n");
        for(int i = 0; i < 7; i++){
            printf("계산 값: %lld\n", dc_odd_sum(num));
        }
        end = clock();
        result = end - start;
        printf("분할 정복 계산 시간 측정 결과 : %lu ms\n", result);

    }else if (select == 3)
    {
        printf("순차적 계산 시작!\n");
        start = clock();
        for(int i = 0; i < 7; i++){
            printf("계산 값: %lld\n", for_even_sum(num));
        }
        end = clock();
        result = end - start;
        printf("순차적 계산 시간 측정 결과 : %lu ms\n", result);

        start = clock();
        printf("분할 정복 계산 시작\n");
        for(int i = 0; i < 7; i++){
            printf("계산 값: %lld\n", dc_even_sum(num));
        }
        end = clock();
        result = end - start;
        printf("분할 정복 계산 시간 측정 결과 : %lu ms\n", result);

    }else{
        printf("보기에 없는 선택입니다.\n");
        return 0;
    }
    

    return 0;

}


long long int dc_sum(long long int n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 1)
        return dc_sum(n - 1) + n;
    else
        return dc_sum(n / 2) * 2 + (n / 2) * (n / 2);
}

long long int for_sum(long long int n)
{
    long long int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

long long int for_odd_sum(long long int n){
    long long int sum = 0;
    for(int i = 1; i <= n; i += 2){
        sum += i;
    }
    return sum;
}

long long int for_even_sum(long long int n){
    long long int sum = 0;
    for(int i = 2; i <= n; i += 2){
        sum += i;
    }
    return sum;
}


//분할정복을 이용해 홀수 값 구하기
long long int dc_odd_sum(long long int n) {
    if (n == 1){
        return 1; 
    }
    else if(n % 2 == 0){
        return dc_odd_sum(n - 1);
    }
    else{ 
        return dc_sum(n/2) * (n /2) ;
    } 

}

//분할정복을 이용해 짝수 값 구하기
long long int dc_even_sum(long long int n) { 
    if (n == 2){
        return 2;
    } 
    else if(n % 2 == 1){
        return dc_even_sum(n - 1);
    }
    else {
        return dc_even_sum(n / 2) * 2 + ; 
    }
}





/*
to-do
(1)상위 코드가 논리적으로 올바르게 동작할 수 있도록 고치고, main()의 코드를 함수/반복문등을 이용하여 간소화 하시오.
(2) 본 프로그램에 1 부터 n 까지 홀수 만 합하는 함수를 추가하시오(조건: 1< n <1000000000, 순차/분할 2개의 함수 작성).
(3) 본 프로그램에 1 부터 n 까지 짝수 만 합하는 함수를 추가하시오(조건: 1< n <1000000000, 순차/분할 2개의 함수 작성).
(4) 1 부터 n 까지 합, 홀수 합, 짝수 합을 키보드로 입력받아 선택 후 동작할 수 있도록 프로그램을 만드시오(입력 값: 변수 n, 전체/홀수/짝수에 대한 동작 수행 변수 select).
(5) 전체 코드에 대하여 중요하다 생각되는 부분은 주석을 통해 설명하시오.
*�����: to-do �� (1) - (4)�� ����� �ϳ��� C ���α׷�(.c)
*/