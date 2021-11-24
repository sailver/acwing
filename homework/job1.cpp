#include <stdlib.h>
#include <stdio.h>

//SwapInt，交换x和y指向的内存地址的值
bool SwapInt(int *x, int *y);

//ThreeIntSort，输入的整数存放在x1，x2，x3指向的内存地址
//输出：要求x1，x2，x3地址中存放的整数是按照从小到大的顺序排好的
bool ThreeIntSort(int *x1, int *x2, int *x3);

//FourIntSort，输入的整数存放在x1，x2，x3，x4指向的内存地址
//输出：要求x1，x2，x3，x4地址中存放的整数是按照从小到大的顺序排好的
bool FourIntSort(int *x1, int *x2, int *x3, int *x4);

//ThreeIntSort，输入的整数存放在x1，x2，x3，x4，x5指向的内存地址
//输出：要求x1，x2，x3，x4，x5地址中存放的整数是按照从小到大的顺序排好的
bool FiveIntSort(int *x1, int *x2, int *x3, int *x4, int *x5);

int main()
{
    int a, b, c, d, e;

    //从命令行读入5个整数，放在a b c d e五个变量里
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    //补充实现代码

    if (ThreeIntSort(&a, &b, &c))
        printf("\n 前三个整数排序结果：%d %d %d\n", a, b, c);

    if (FourIntSort(&a, &b, &c, &d))
        printf("\n 前四个整数排序结果：%d %d %d %d\n", a, b, c, d);

    if (FiveIntSort(&a, &b, &c, &d, &e))
        printf("\n 前五个整数排序结果：%d %d %d %d %d\n", a, b, c, d, e);

    return 0;
}

bool ThreeIntSort(int *x1, int *x2, int *x3)
{
    if (*x1 > *x2 && *x1 > *x3)
    {
        SwapInt(x1, x3);
    }
    if (*x3 < *x2)
    {
        SwapInt(x2, x3);
    }
    if (*x2 < *x1)
    {
        SwapInt(x1, x2);
    }
    return true;
}

bool FourIntSort(int *x1, int *x2, int *x3, int *x4)
{
    if (*x1 > *x2 && *x1 > *x3 && *x1 > *x4)
    {
        SwapInt(x1, x4);
    }

    if (ThreeIntSort(x2, x3, x4))
    {
        if (ThreeIntSort(x1, x2, x3))
        {
            return true;
        }
    }

    return false;
}

bool FiveIntSort(int *x1, int *x2, int *x3, int *x4, int *x5)
{
    if (*x1 > *x2 && *x1 > *x3 && *x1 > *x4 && *x1 > *x5)
    {
        SwapInt(x1, x5);
    }

    if (FourIntSort(x2, x3, x4, x5))
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
