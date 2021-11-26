// * 15:07
// 理解：集合版的dijkstra，原理基本一样，只是把每次更新时取的 "离起点最近的点" 改成了 "离集合最近的点"
//      --最短路选点，生成树选边--

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        st[t] = true;
        if(i && dist[t] == INF)return INF;
        for(int j = 1; j <= n; j++)
            if(!st[j])  // * 防止自环   // * 35:00
                dist[j] = min(dist[j], g[t][j]);    //与dijkstra不同， 这里求的是到集合的最短路

        if(i)res += dist[t];
    }
    return res;
}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin>>n>>m;
    while(m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prim();
    if(t==INF)puts("impossible");
    else printf("%d\n", t);
    return 0;
}