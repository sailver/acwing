#include <iostream>
using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x)
    {
        k++;
        if (k == N)
            k = 0;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(h, 0x3f, sizeof h);
    //  ! memset是对每个字节进行赋值！
    //  * 这里的意思实际是对四个字节都赋值0x3f，
    //  * 也就是实际值为0x3f3f3f3f
    //  * 更多内容：https://blog.csdn.net/tcherry/article/details/37606277

    while (n--)
    {
        char op[2];
        int x;
        scanf("%s5=%d", op, &x);
        int k = find(x);
        if (*op == 'I')
            h[k] = x;
        else
        {
            if (h[k] != null)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}