// * 超棒的算法！一共两步：1.给所有边权排序O(mlogm)； 2.进行并查集操作O(m)

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 200010;

int n, m;
int p[N];
int cnt = 0, res = 0;

struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const
    { //重载小于号
        return w < W.w;
    }
} edges[N];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

void kruskal()
{
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            cnt++;
            res += w;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    kruskal();
    if (cnt < n - 1)
        puts("impossible");
    else
        printf("%d\n", res);

    return 0;
}