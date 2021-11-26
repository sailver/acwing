
// * 坐标：第三章（二）30:00

//这题虽然有重边和自环，但由于边权都为正，所以自环不用考虑，重边取最短即可

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) //每次都找一个未被标记的，且dist最小的数
                t = j;
        if (t == n)
            break; //已经找到n了，可以提前退出了（可加可不加） ！ 加了的话无法就解决负权边问题

        st[t] = true; //打上标记

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]); //以t为中转站更新所有t能到达的点的最短路（不能到达的话还是inf
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    else
        return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c); //考虑到有重边情况，取最短边就好
    }

    int t = dijkstra();
    printf("%d\n", t);
    return 0;
}
