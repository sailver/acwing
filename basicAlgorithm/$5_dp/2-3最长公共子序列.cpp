#include <iostream>
#include <algorithm>
using namespace std;

/*
    状态表示：
    集合：所有在第一个序列的前i个字母中出现，
        且在第二个序列的前j个字母中出现的公共子序列
*/


const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }

    printf("%d\n", f[n][m]);

    return 0;
}
