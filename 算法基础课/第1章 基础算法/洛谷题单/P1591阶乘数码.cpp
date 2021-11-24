//高精度
#include <iostream>
#include <vector>
using namespace std;
vector<int> a;

void factorial(int n)
{
    for(int i=1;i<=n;i++)
    {
        int tmp = 0, j = 0;
        for(;j<a.size();j++)tmp += a[j] * i, a[j] = tmp%10, tmp /= 10;
        while(tmp)a.push_back(tmp%10), tmp/=10;
    }
}
int find(int x)
{
    long long c=0;
    while(a.size())
    {
        if(a.back() == x)c++;
        a.pop_back();
    }
    return c;
}

int main()
{
    int t,n,x;
    cin>>t;
    while(t--)
    {
        a.push_back(1);
        cin>>n>>x;
        factorial(n);
        cout<<find(x)<<endl;
    }
    return 0;
}