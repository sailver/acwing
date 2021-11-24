#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// * 以最后一次合并的位置作为分界线  1:40:00
// * f[] = f[i,k]+f[k+1,j]+s[j]-s[i-1]  //左边代价加上右边代价加上这一步的代价（即区间内总质量）

const int N = 310;

int n;
int s[N];
int f[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);

    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1];

    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int l = i, r = i + len - 1;
            f[l][r] = 1e8;
            for (int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }

    printf("%d\n", f[1][n]);
    return 0;
}