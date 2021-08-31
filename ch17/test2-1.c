#include <stdio.h>

struct marrige
{
    char name[20];
    int age;
    char sex;
    double height;
};

struct marrige m1 = {"Andy", 22, 'm', 187.5};
struct marrige *mp = &m1;

int main(void)
{
    printf("%s\n", mp ->name);
    printf("%d\n", mp->age);
    printf("%c\n", mp->sex);
    printf("%.1lf\n", mp->height);

    return 0;
}