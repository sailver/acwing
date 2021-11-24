#include <iostream>
#include <algorithm>
using namespace std;

const int N = 55;
bool g[N][N];
int br[N], wr[N], bl[N], wl[N], brow, bline, wrow, wline;
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &g[i][j]);
            if (g[i][j])
                br[i]++, bl[j]++;
            else
                wr[i]++, wl[j]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        brow += pow(2, br[i]) - br[i] - 1;
        wrow += pow(2, wr[i]) - wr[i] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        bline += pow(2, bl[i]) - bl[i] - 1;
        wline += pow(2, wl[i]) - wl[i] - 1;
    }
}