// * 麻烦点在于要删除的是第k个插入的点
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 100010;

int n, m;
// * ph[k]: 第k个插入点的下标
// * hp[j]: j下标对应的点是第几个插入的
// * ph[k] = j; hp[j] = k;
int h[N], ph[N], hp[N], siz;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= siz && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= siz && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        heap_swap(u / 2, u);
        u /= 2;
    }
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        char op[10];
        int k, x;

        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            siz++;
            m++;
            ph[m] = siz, hp[siz] = m;
            h[siz] = x;
            up(siz);
        }
        else if (!strcmp(op, "PM"))
            printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, siz);
            siz--;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, siz);
            siz--;
            down(k), up(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}