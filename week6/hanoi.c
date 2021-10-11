#include <stdio.h>

void hanoi(int, char, char, char);

int main(void)
{
   int n;
   scanf("%d", &n);
   hanoi(n, 'a', 'b', 'c');   // 재귀시작

   return 0;
}

void hanoi(int n, char from, char temp, char to)
{
   if (n == 1)
   {
      printf("1번원반 %c-->%c\n", from, to);
   }
   else
   {
      hanoi(n - 1, from, to, temp);   // to와 temp의 위치를 바꾼다

      printf("%d번원반 %c-->%c\n", n, from, to);
      hanoi(n - 1, temp, from, to);   // from과 temp의 위치를 바군다
   }   
}