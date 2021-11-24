//把所有有交集的区间合并，输出合并后的集合数
//贪心
/*
步骤： 
1.按区间左端点排序
2.左端点相同的进行右端点排序
3.再判断包含情况
 */

 //struct写法
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
struct Node {
    int x;
    int y;
}a[N];
bool setCmp(const Node &a, const Node &b)
{
    if(a.x != b.x)return a.x < b.x;
    else return a.y < b.y;
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)cin>>a[i].x>>a[i].y;
    sort(a,a+n,setCmp);
    //for(int i = 0; i < n; i++)cout<<a[i].x<<' '<<a[i].y<<endl;
    Node cur = a[0];
    int count = 0;
    for(int i = 1; i < n; i++)
    {
        //cout<<cur.x<<' '<<cur.y<<endl;
        if(cur.y < a[i].x)
        {
            count++;
            cur = a[i];
        }
        else 
            cur.y = max(cur.y, a[i].y);
    }
    
    if(cur.x != cur.y)count++;
    cout<<count;
}

//PII写法