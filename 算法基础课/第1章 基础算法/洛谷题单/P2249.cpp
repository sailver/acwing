
//二分

#include <stdio.h>
const int N = 1000010;//出现re(runtime error):这个弄错了!!!
int a[N];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    while(m--)
    {
        int l=1,r=n,mid,x;
        scanf("%d",&x);
        while(l<r)
        {
            mid = (l+r)>>1;
            if(a[mid]>=x)r = mid;
            else l = mid+1;
        }
        if(a[l] == x)printf("%d ",l);
        else printf("-1 ");
    }
}