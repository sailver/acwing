#include <iostream>
using namespace std;

const int N = 10;

int n;
int path[N];
bool st[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            //path[u] = 0   没必要，后面会被覆盖
            st[i] = false;  // * 恢复现场
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}