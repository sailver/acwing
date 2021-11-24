#include <stdlib.h>
#include <stdio.h>

//SwapInt������x��yָ����ڴ��ַ��ֵ
bool SwapInt(int *x, int *y);

//ThreeIntSort����������������x1��x2��x3ָ����ڴ��ַ
//�����Ҫ��x1��x2��x3��ַ�д�ŵ������ǰ��մ�С�����˳���źõ�
bool ThreeIntSort(int *x1, int *x2, int *x3);

//FourIntSort����������������x1��x2��x3��x4ָ����ڴ��ַ
//�����Ҫ��x1��x2��x3��x4��ַ�д�ŵ������ǰ��մ�С�����˳���źõ�
bool FourIntSort(int *x1, int *x2, int *x3, int *x4);

//ThreeIntSort����������������x1��x2��x3��x4��x5ָ����ڴ��ַ
//�����Ҫ��x1��x2��x3��x4��x5��ַ�д�ŵ������ǰ��մ�С�����˳���źõ�
bool FiveIntSort(int *x1, int *x2, int *x3, int *x4, int *x5);

int n, m, sum;

int main()
{
    int a, b, c, d, e;
    scanf("%d", &n);

    //�������ж���5������������a b c d e���������
    //����ʵ�ִ���

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        m = 0;
        if (FourIntSort(&a, &b, &c, &d))
            sum += m, printf("\n m:%d\n", m);
    }
    printf("a:%d", sum / n);

    return 0;
}

bool ThreeIntSort(int *x1, int *x2, int *x3)
{
    if ((m++) && *x1 > *x2 && *x1 > *x3)
    {
        SwapInt(x1, x3);
    }
    if ((m++) && *x3 < *x2)
    {
        SwapInt(x2, x3);
    }
    if ((m++) && *x2 < *x1)
    {
        SwapInt(x1, x2);
    }
    return true;
}

bool FourIntSort(int *x1, int *x2, int *x3, int *x4)
{
    if ((m++) && *x1 > *x2 && *x1 > *x3 && *x1 > *x4)
    {
        SwapInt(x1, x4);
    }

    if ((m++) && ThreeIntSort(x2, x3, x4))
    {
        if ((m++) && ThreeIntSort(x1, x2, x3))
        {
            return true;
        }
    }

    return false;
}

bool FiveIntSort(int *x1, int *x2, int *x3, int *x4, int *x5)
{
    if ((m++) && *x1 > *x2 && *x1 > *x3 && *x1 > *x4 && *x1 > *x5)
    {
        SwapInt(x1, x5);
    }

    if ((m++) && FourIntSort(x2, x3, x4, x5))
    {
        if (FourIntSort(x1, x2, x3, x4))
        {
            return true;
        }
    }

    return false;
}

bool SwapInt(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return true;
}
