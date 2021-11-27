#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    struct student{ //이름과 성적 입력받을 구조체 선언
        char name[80];
        double grade;
    };

    struct student list[5] = {0};//구조체 배열 선언
    int i;

    for(i = 0; i < 3; i++){//3명의 학생을 받음
        printf("name: ");
        gets(list[i].name); //이름입력
        printf("grade: ");
        scanf("%lf", &list[i].grade);//성적입력
        fflush(stdin); //성적입력시 엔터가 남아있어서 버퍼 비우기
    }

    for(i = 0; i < 3; i++){
        printf("%s, %.1lf\n", list[i].name, list[i].grade);//최종 출력

    }

    return 0;

    
}