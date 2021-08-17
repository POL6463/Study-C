#include <stdio.h>

int main(void)
{
    int hour, min, sec;
    double time = 3.76;

    hour = (int)time;

    time = time - hour;

    min = (int)(time * 60);

    time = time * 60 - min;

    sec = (int)(time * 60);



    printf("3.76시간은 %d시간 %d분 %d초 입니다\n", hour, min, sec);

    return 0;

}