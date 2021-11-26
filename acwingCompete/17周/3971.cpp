#include <iostream>
#include<algorithm>
using namespace std;

const int N = 105;
int m, n, k;
int a[N];

int find()
{
    int ans = 120;
    for(int i = 0; i<n;i++)
    {
        if(a[i] && k%a[i] == 0)
        {
            ans = min(k/a[i],ans);
        }
    }
    return ans;
}

int main()
{
    cin >> m >> n >> k;
    // while(m--)
    // {
    //     cin>>n>>k;
    //     for(int i = 0; i<n;i++)
    //     {
    //         scanf("%d ", &a[i]);
    //     }
    //     printf("%d\n", find());
    // }
    return 0;
}