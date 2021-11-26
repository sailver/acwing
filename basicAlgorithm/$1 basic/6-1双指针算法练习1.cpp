/* 
题目：找到一串数字中不含重复数字的最长连续串，并输出其长度
*/
#include <iostream>
using namespace std;
const int N = 100010;
int a[N],s[N];//a[N](存储数字串),s[N](记录该串中数字出现次数);
int main()
{
    int n,res=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0,j=0;i<n;i++)
    {
        s[a[i]]++;
        while(s[a[i]]>1)
        {
            s[a[j]]--;
            j++;
        }
        res = max(res,i-j+1);
    }
    cout<<res;
}
