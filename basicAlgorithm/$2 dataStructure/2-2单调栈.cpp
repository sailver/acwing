//找到一组数中，每个数左边离他最近的小于他的数，若无则输出-1
#include <iostream>
using namespace std;
const int N = 100010;

int n;
int stk[N], tt;

//复杂度O(n);
int main()
{
    ios::sync_with_stdio(false);  //加速输入
    cin.tie(0);  //加速
    cout.tie(0);  //加速
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while(tt && stk[tt] >= x) tt--;
        if(tt) cout << stk[tt] << ' ';
        else cout << -1 <<' ';
        stk[++tt] = x;
    }
    return 0;
}