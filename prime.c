#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrime(int);

int main(void)
{
   int num;
   printf("2이상의 정수: ");
   scanf("%d", &num);
   isPrime(num);
   return 0;
}

int isPrime(int num)
{
   int i, j, cnt = 0;
   for (i = 2; i <= num; i++)
   {
      for (j = 0; j <= i; j++)
      {
         if (i % j == 0)
         {
            if (i > j)
            {
               break;
            }
            else
            {
               printf("%5d", i);
               cnt++;
               if (cnt % 5 == 0)
               {
                  printf("\n");
               }
            }
         }
      }
   }
   return 0;
}