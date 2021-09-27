#include <stdio.h>

int main(void) {
    char day;
    int week;

    scanf("%c", &day);

    

    switch (day)
    {
    case 'M':
    case 'm':
    case 'T':
    case 't':
    case 'W':
    case 'w':
    case 'F':
    case 'f':
    case 'H':
    case 'h':
        printf("평일\n");
        break;
    
    case 'S':
    case 's':
    case 'N':
    case 'n':
        printf("주말\n");
        break;

    default:
        printf("요일이 아닙니다\n");
        break;
    }

    return 0;

}