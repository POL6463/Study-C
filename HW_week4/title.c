#include <stdio.h>

int main(void) {
    char name[100];
    int num;
    int age;

    scanf("%s", name);
    scanf("%d%d", &num, &age);

    printf("성명: %s\n학번: %d\n나이: %d\n", name, num, age);
    return 0;
}