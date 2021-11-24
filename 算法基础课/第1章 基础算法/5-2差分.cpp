/* 
对于数列{an},可以构造{bn}使得an为bn的前n项和（前缀和）
这样在做对an的操作时，可以转化为对bn进行操作
典型的，如本题，对an中l到r的元素进行+c的操作
可以转化为对b数列进行：b[l]+=c,b[r+1]-=c的操作
将o(n)的操作变成了o(1)的操作，大大节省了时间
*/
#include <iostream>
using namespace std;
const int N = 100010;
int b[N];
void insert(int l, int r, int c)
{
    b[l] += c;
    b[r+1] -= c;
}
int main()
{
    int n,m,t,l,r,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        insert(i,i,t);
    }
    while(m--)
    {
        cin>>l>>r>>c;
        insert(l,r,c);
    }
    for(int i=1;i<=n;i++)
    {
        b[i] += b[i-1];
        cout<<b[i]<<' ';
    }
    return 0;
}