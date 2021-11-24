#include <iostream>
#include <algorithm>
using namespace std;

/*
    状态表示：
        集合：到第i个点的所有路径
        属性：max
    状态计算：
        f[i]
        来自前一个数
        for(int j = 1; j < i; j++)
            f[i] = max(f[i], f[j]+1);
*/

const int N = 1010;
int n;
int a[N], f[N];
int g[N], b[N]; //保存序列
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                if (f[i] < f[j] + 1)
                {
                    f[i] = f[j] + 1;
                    g[i] = j;
                }
    }

    int k = 1;
    for (int i = 1; i <= n; i++)
        if (f[k] < f[i])
            k = i;
    cout << f[k];
    for (int i = 0, len = f[k]; i < len; i++)
    {
        b[i] = a[k];
        k = g[k];
    }
    for (int i = 0, len = f[k]; i < len; i++)
        cout << b[i];
    return 0;
}