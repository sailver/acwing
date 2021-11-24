#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int s,v,m;
    cin>>s>>v;
    m = s / v;
    if(m*v<s)m++;
    m = 24*60+7*60+50 - m;
    cout<<setw(2)<<setfill('0')<<(m/60)%24<<':'
    <<setw(2)<<setfill('0')<<m%60;
}