#include <stdio.h>
#include <time.h>

/*
    1�� ���� [���� 2] �ڵ�, �й�:           ,�̸�:
*/

long long int dc_sum(int);
long long int for_sum(int);

int main() {
    clock_t start, end, result;
    /*
        Ű���带 ���� �Է� ���� ����
        n, select
    */
    printf("������ ��� ����!\n");
    //������ ���
    start = clock();
    for(int i = 0 ; i < 7; i++)
    printf("��� ��: %lld\n", for_sum(1000000000));
    printf("��� ��: %lld\n", for_sum(1000000000));
    printf("��� ��: %d\n", for_sum(1000000000));
    printf("��� ��: %d\n", for_sum(1000000000));
    printf("��� ��: %d\n", for_sum(1000000000));
    printf("��� ��: %d\n", for_sum(1000000000));
    printf("��� ��: %d\n", for_sum(1000000000));
    end = clock();

    result = end - start;
    printf("������ ��� �ð� ���� ��� : %lu ms\n", result);

    //���� ���� ����
    printf("���� ���� ��� ����!\n");

    start = clock();
    printf("��� ��: %lld\n", dc_sum(1000000000));
    printf("��� ��: %lld\n", dc_sum(1000000000));
    printf("��� ��: %d\n", dc_sum(1000000000));
    printf("��� ��: %d\n", dc_sum(1000000000));
    printf("��� ��: %d\n", dc_sum(1000000000));
    printf("��� ��: %d\n", dc_sum(1000000000));
    printf("��� ��: %d\n", dc_sum(1000000000));
    end = clock();

    result = end - start;
    printf("���� ���� �ð� ���� ��� : %lu ms\n", result);

    return 0;
}

long long int dc_sum(int n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 1)
        return dc_sum(n - 1) + n;
    else
        return dc_sum(n / 2) * 2 + (n / 2) * (n / 2);
}

long long int for_sum(int n)
{
    long long int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    return sum;
}

/*
to-do
(1) ���� �ڵ尡 ���������� �ùٸ��� ������ �� �ֵ��� ��ġ��, main()�� �ڵ带 �Լ�/�ݺ������� �̿��Ͽ� ����ȭ �Ͻÿ�.
(2) �� ���α׷��� 1 ���� n ���� Ȧ�� �� ���ϴ� �Լ��� �߰��Ͻÿ�(����: 1< n < 1000000000, ����/���� 2���� �Լ� �ۼ�).
(3) �� ���α׷��� 1 ���� n ���� ¦�� �� ���ϴ� �Լ��� �߰��Ͻÿ�(����: 1< n < 1000000000, ����/���� 2���� �Լ� �ۼ�).
(4) 1 ���� n ���� ��, Ȧ�� ��, ¦�� ���� Ű����� �Է¹޾� ���� �� ������ �� �ֵ��� ���α׷��� ����ÿ�(�Է� ��: ���� n, ��ü/Ȧ��/¦���� ���� ���� ���� ���� select).
(5) ��ü �ڵ忡 ���Ͽ� �߿��ϴ� �����Ǵ� �κ��� �ּ��� ���� �����Ͻÿ�.
*�����: to-do �� (1) - (4)�� ����� �ϳ��� C ���α׷�(.c)
*/
