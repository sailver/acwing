//* Trie : 高效地存储和查找字符串集合的数据结构

#include <iostream>
using namespace std;

const int N = 100010;

//!son[p][u]解释： p：父亲的位置，u：儿子的值，son[p][u]:属于p的，且值为u的儿子的位置
int son[N][26], cnt[N], idx;
char str[N];

//* 插入操作
void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

//* 查询操作
int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char op[2];
        scanf("%s%s", op, str);
        if (op[0] == 'I')
            insert(str);
        else
            printf("%d\n", query(str));
    }
    return 0;
}