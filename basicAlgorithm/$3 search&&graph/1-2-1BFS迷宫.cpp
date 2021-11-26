// * 走迷宫（权重相同的最短路）
// 当题目出现类似所有边的长度都是1的描述的时候，意味着可以用宽搜来做
// * 关于dp：dp可以认为是特殊的最短路问题
// ! 关键思想:01:01:00
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N]; // 存图
int d[N][N]; // 距离
PII q[N * N], Prev[N][N];

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = {0, 0};

    memset(d, -1, sizeof d);
    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (hh <= tt)
    {
        auto t = q[hh++];

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                Prev[x][y] = t; //记录路径
                q[++tt] = {x, y};
            }
        }
    }

    int x = n - 1, y = m - 1;
    while (x || y)
    {
        cout << x << ' ' << y << endl; //输出路径
        auto t = Prev[x][y];
        x = t.first, y = t.second;
    }
    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    cout << bfs() << endl;
    return 0;
}