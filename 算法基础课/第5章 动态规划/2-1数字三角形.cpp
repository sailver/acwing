#include <iostream>
#include <algorithm>
using namespace std;
/*

复习一下
    动态规划：
    1.状态表示
        集合： 所有从起点，走到(i,j)的路径
        属性： max
    2.状态计算（集合划分）
    f(i,j)  //* 视频位置：19:00
        [曲线救国]
        分为来自左上和来自右上
            左上：f[i-1,j-1] +a[i,j]
            右上：f[i-1,j] + a[i,j]

*/

const int N = 510, INF = 1e9;

int n;
int a[N][N];
int f[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i + 1; j++)
            f[i][j] = -INF;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);

    int res = -INF;
    for (int i = 1; i <= n; i++)
        res = max(res, f[n][i]);

    cout << res << endl;

    return 0;
}