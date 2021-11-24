#include <iostream>
using namespace std;
const int N = 100010;

int m;
int e[N], l[N], r[N], idx;
//结构形式会很复杂，用数组（在竞赛）更方便

// 初始化
void init()
{
    // 0表示左端点，1表示右端点，两个初始化端点都不在实际链表中
    r[0] = 1, l[1] = 0;
    idx = 2;
}

//k右边插入一个节点  *注意，k右边的第一个数未必是k+1，所以全程不能出现k+1
//如果要在k左边插入一个节点，直接用add(l[k], x);
void add(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k], l[idx] = l[k+1];
    l[r[k]] = idx, r[k] = idx;  //顺序不能反
}

//删除k节点
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}