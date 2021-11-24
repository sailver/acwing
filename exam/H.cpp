#include <iostream>
using namespace std;

const int N = 300010;

int n, m;
char p[N], s[N];
int ne[N];
int ans[N];

int main()
{
    int k = 0, cnt = 0;
    memset(ans, 0, sizeof ans);
    cin >> n >> k >> s + 1;
    for (int i = 0; i < k; i++)
    {
        int st[];
        memset(p, 0, sizeof p);
        cin >> p + 1;
        for (int i = 2, j = 0; i <= n; i++)
        {
            while (j && p[i] != p[j + 1])
                j = ne[j];
            if (p[i] == p[j + 1])
                j++;
            ne[i] = j;
        }

        for (int i = 1, j = 0; i <= m; i++)
        {
            while (j && s[i] != p[j + 1])
                j = ne[j];
            if (s[i] == p[j + 1])
            {
                j++;
                ans[cnt]++;
            }
            if (j == n) //匹配成功
            {
                printf("%d ", i - n + 1);
                j = ne[j];
                cnt++;
            }
        }
    }

    return 0;
}