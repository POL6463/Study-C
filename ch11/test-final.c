#include <stdio.h>

int main(void)
{
    int count;
    int count2;
    char ch;
    int res;

    while (1)
    { 
      
        
        while(1)
        {
            
            res = scanf("%c", &ch);
            
            if (ch == '\n') break;
            count2++;
            
        }
        if (count2 > count)
        {
            count = count2;
            count2 = 0;
        }
        

        
        if (res == EOF) break;
        
    }

    printf("가장 긴 단어의 길이 : %d\n", count);

    return 0;
    
}