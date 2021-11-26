// * 并查集：
// * 1.将两个集合合并
// * 2.询问两个元素是否在一个集合中

// *在O(1)复杂度内快速完成两个操作

// *基本原理：
// *     每个集合用一棵树来表示。
// *     树根的编号就是整个集合的编号。
// *     每个节点存储它的父节点,用p[x]表示x的父节点

// *1. 判断树根： if(p[x]==x)   (根的父节点就是本身)
// *2. 求x的集合编号： while(p[x]!=x)x=p[x];  (一直向上找到根节点)
// *3. 如何合并两个集合：px是x的集合编号，py是y的集合编号。p[x] = y;

// ! 但是这样还不够好，第2个问题的解决依然太慢
// * 所以神优化出现：
// * 并查集核心：路径压缩 -> O(1) ; 其实还有按秩合并的方法，用的很少
// ! 所以变更为迭代函数if(p[x]!=x)p[x]=find(p[x]);(每个非根节点的父节点都是根)
#include <iostream>
using namespace std;

const int N = 100010;
int n,m;
int p[N];

int find(int x) // * 返回x的祖宗节点 + 路径压缩(保证大家父节点都是根)
{
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d",&n, &m);

    for(int i = 1; i<=n;i++)p[i] = i;
    while(m--)
    {
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(op[0] == 'M')p[find(a)] = find(b);
        else
        {
            if (find(a) == find(b))puts("Yes");
            else puts("No");
        }
    }
    return 0;
}