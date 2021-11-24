#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int N = 100010, M = 200020;
int n, m, v;
int r[N];
double w[N];
int h[N], e[M], ne[M], idx;
bool st[N], flag;
int cnt;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    if (flag)
        return;
    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int x = u, y = e[i];
        double temp = -(r[x] * 1.0 / (r[y] * 1.0) * w[x]);

        if (!st[y])
        {
            w[y] = temp;
            cnt++;
            cout<<y<<endl;
            dfs(y);
            if (flag)
                return;
        }
        else if (w[y] - temp > 1e-5)
        {
            flag = 1;
            return;
        }
    }
    return;
}

int main()
{
    cin >> n >> m >> v;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    for (int i = 0; i < v && !flag; i++)
    {
        int j = 0;
        double vj = 0;
        cin >> j >> vj;

        if (w[j] && (w[j] - vj) > 1e-5)
        {
            flag = 1;
            break;
        }
        else
        {
            w[j] = vj;
            dfs(j);
        }
    }

    if (flag)
    {
        cout << "0";
        return 0;
    }
    if (cnt == n )
        for (int i = 1; i <= n; i++)
        {
            cout << setiosflags(ios::fixed) << setprecision(8) << w[i] << ' ';
        }
    else if (cnt < n )
        cout << "-1";
    return 0;
}