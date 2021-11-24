#include <bits/stdc++.h>
using namespace std;
void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return; //别忘了
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
        {
            int tmp = q[i];
            q[i] = q[j];
            q[j] = tmp;
        }
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}
int main()
{
    int q[30], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
}