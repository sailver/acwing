
//双指针
//1.0版本 有bug 还没找到 /21/8/13
//已解决，bug: ans数据大小开小了，至少要用long long

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200010;
int a[N];
int main()
{
    int n,c,tmp = 0; 
    long long ans =0;
    cin>>n>>c;

    for(int i=0;i<n;i++)cin>>a[i]; 
    sort(a,a+n);
    
    for(int i=0,j=0;i<n;i++)
    {
        while(i!=0 && a[i] == a[i-1])
        {
            i++;
            ans+=tmp;
        }

        tmp=0;

        while(j<i && a[i]-a[j]>c)j++;

        if(a[i] - a[j] == c)
        {
            do{tmp++,j++;}while(a[j]==a[j-1]);
            ans+=tmp;
        }
    }
    cout<<ans;
}