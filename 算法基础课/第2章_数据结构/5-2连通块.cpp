#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int p[N], siz[N];  // ! 只保证根节点的siz是有意义的 

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }
    while (m--)
    {
        char op[5];
        int a, b;
        scanf("%s", op);

        if (op[0] == 'C')
        {
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)) continue;
            siz[find(b)] += siz[find(a)];
            p[find(a)] = find(b);
        }
        else if (op[1] == '1')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
        {
            scanf("%d", &a);
            printf("%d\n", siz[find(a)]);
        }
    }
}