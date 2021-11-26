#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int wusong, n, a[110];
    cin >> wusong >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a,a+n);
    int c = 1;
    for(;wusong >= 0;c++)
        wusong -= a[c];
    cout<<c-1;
    return 0;
}