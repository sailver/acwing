// ! 用cnt[]记录最短路的边数，若存在cnt[x] >= n则说明出现了负环
// * 01:50:00

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1000010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
    // memset(dist, 0x3f, sizeof dist);     不需要初始化了
    // dist[1] = 0;

    queue<int> q;

    //! q.push(1);      不能只从1出发了，从1出发可能进不了负环
    // st[1] = true;

    for(int i = 1; i <= n; i++) // ! 要从每个点都出发一遍；
    {
        q.push(i);
        st[i] = true;
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n)
                    return true;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    if (spfa())
        puts("Yes");
    else
        puts("No");
    return 0;
}