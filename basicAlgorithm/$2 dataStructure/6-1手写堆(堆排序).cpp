// * 1. 插入一个数  heap[++size] = x; up(size);
// * 2. 求集合当中的最小值  heap[1];
// * 3. 删除最小值  heap[1] = heap[size]; size--;down(1)
// * 4. 删除任意一个元素    heap[k] = heap[size]; size--;down(k), up(k);
// * 5. 修改任意一个元素    heap[k] = x; down(k), up(k);

// * 堆是一个完全二叉树
// * 完全二叉树：除最后一层以外，所有层都是满的，最后一层从左到右依次排布
// * 小根堆：爸爸永远小于等于儿子
// * 存储：从上到下，从左到右，从 1 开始依次存入
// *       x的左儿子：2x，  x的右儿子：2x+1

// * 操作：
// * 1.down(x)
// * 2.up(x)

#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int h[N], siz;

void down(int u)
{
    int t = u;
    if (u * 2 <= siz && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= siz && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        swap(h[u / 2], h[u]);
        u /= 2;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    siz = n;
    for (int i = n / 2; i; i--)
        down(i);
    while (m--)
    {
        printf("%d ", h[1]);
        h[1] = h[siz];
        siz--;
        down(1);
    }
}