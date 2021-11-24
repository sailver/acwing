#include <iostream>
using namespace std;
const int N = 100010;
//head -> 头指针
int head, e[N], ne[N], idx;
void init() //初始化
{
    head = -1;
    idx = 1; //起始为1的情况下后面的k传参时不需要-1
}
void add_to_head(int x) //头插法
{
    e[idx] = x, ne[idx] = head, head = idx++;
}
void add(int k, int x) //k后插入一个节点
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}
void remove(int k) //删除k后一个节点
{
    if (k == 0)
        head = ne[head]; //如果删除第一个节点
    else
        ne[k] = ne[ne[k]];
}
int main()
{
    init();
    int m;
    cin >> m;
    while (m--)
    {
        int k, x;
        char op;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            remove(k);
        }
        else
        {
            cin >> k >> x;
            add(k, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    return 0;
}