#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    int ch;
    int i, j, k;
    int an, am, bn, bm;
    int **arrA;
    int **arrB;
    int **arrC;
    

    fp = fopen("a.txt", "r");


    char strTemp[255];
	char *pStr;

    fgets(strTemp, sizeof(strTemp), fp);

    an = strTemp[0] - '0';
    am = strTemp[2] - '0';

    bn = strTemp[4] - '0';
    bm = strTemp[6] - '0';

    arrA = (int**) malloc (sizeof(int*) * an);
    for(i = 0; i < an; i++){
        arrA[i] = (int*) malloc (sizeof(int) * am);
    }

    arrB = (int**) malloc (sizeof(int*) * bn);
    for(i = 0; i < bn; i++){
        arrB[i] = (int*) malloc (sizeof(int) * bm);
    }

    arrC = (int**) malloc (sizeof(int*) * an);
    for(i = 0; i < an; i++){
        arrC[i] = (int*) malloc (sizeof(int) * bm);
    }




    char a[255];
    char b[255];
    char c[255];

    for(i = 0; i < an; i++){
        fgets(a, sizeof(a), fp);
        for(j = 0; j < am; j++){
            arrA[i][j] = (a[j * 2] - '0');
        }
    }

    for(i = 0; i < bn; i++){
        fgets(b, sizeof(b), fp);
        for(j = 0; j < bm; j++){
            arrB[i][j] = (b[j * 2] - '0');
        }
    }

    for(i = 0; i < an; i++){
        for(j = 0; j < bm; j++){
            arrC[i][j] = 0;
            for(k = 0; k < am; k++){
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    for(i = 0; i < an; i++){
        for(j = 0; j < bm; j++){
            printf("%d  ", arrC[i][j]);
        }
        printf("\n");
    }





    for (int i=0; i < an; i++){
        free(arrA[i]);
    }
    free(arrA);

    for (int i=0; i < bn; i++){
        free(arrB[i]);
    }
    free(arrB);

    for (int i=0; i < an; i++){
        free(arrC[i]);
    }
    free(arrC);
    

    fclose(fp);

    return 0;
}