#include <iostream>
using namespace std;
vector<int> a;
void Mai(int p)
{
    for(int j = 0; j<p; j++)
    {
        int tmp = 0;
        for(int i=0;i<a.size();i++)
        {
            tmp += a[i] * 2;
            a[i] = tmp%10;
            tmp/=10;
        }
        while(tmp)a.push_back(tmp%10),tmp/=10;
    }
    a[a.size()-1]--;
    cout<<a.size()<<endl;
    for(int i=)
}
int main()
{
    a.push_back(1);
    int p;
    cin>>p;
    Mai(p);
}