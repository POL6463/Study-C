#include <stdio.h>
void call_Human();
void call_Dog();
int god;

int main()
{
int god=10;
    {
    int god=100;
    printf("First God: %d\n", god);
    }
    printf("Second God: %d\n", god);
    call_Human();
    call_Human();
    call_Human();
    call_Dog();
    call_Dog();
    call_Dog();
    return 0;
}

void call_Human()
{
    int human=1000;
    god++;
    human++;
    printf("God: %d\n", god);
    printf("Human: %d\n", human);
}

void call_Dog()
{
    static int dog=10000;
    god++;
    dog++;
    printf("God: %d\n", god);
    printf("Human: %d\n", dog);
}