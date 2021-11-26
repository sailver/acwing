#include <iostream>
using namespace std;
int lowbit(int x)
{
    return x&(-x);  
    /* 
    e.g: x = 10100100
        ~x = 01011011
        -x = 01011100  ( -x = ~x + 1 )
    x&(-x) = 00000100  (只含最低位的1)
     */
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        int c = 0;
        while(k)k -= lowbit(k),c++;
        cout<<c<<' ';
    }
}