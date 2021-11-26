//大数除以小数
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> div(vector<int> &A, int b,int &r)
{
    vector<int> C;
    for(int i=A.size()-1;i>=0;i--)
    {
        r = r*10 + A[i];
        C.push_back(r/b);
        r %= b;
    }
    reverse(C.begin(),C.end());
    while(C.back() == 0 && C.size()>1)C.pop_back();
    return C;
}
int main()
{
    string a;
    int b,r=0;
    cin>>a>>b;
    vector<int> A,C;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    C = div(A,b,r);
    for(int i=C.size()-1;i>=0;i--)printf("%d",C[i]);
    cout<<endl<<r;
    return 0;
}