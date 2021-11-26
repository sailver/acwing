//* 哈希表
//* 1. 存储结构
//* 1.1开放寻址法
//* 1.2拉链法
//* 2. 字符串哈希方法

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100003;
// ! 取模的数最后要取十万以后的第一个*质数*，可以使冲突概率降低

//* 拉链法
//* 删除：逻辑删除
int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;                  //*考虑到x为负数的情况
    e[idx] = x, ne[idx] = h[k], h[k] = idx++; //*头插法
}
bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
    {
        if (e[i] == x)
            return true;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(h, -1, sizeof(h));
    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (*op == 'I')
            insert(x);
        else
        {
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }
    }
}