/*

1. 欧拉函数：φ(n) : 1 ~ n 中与n互质的数的个数
    n = (p1 ^ a1)(p2 ^ a2)(p3 ^ a3)...
    公式：φ(n) = n(1 - n/p1)(1 - n/p2)(1 - n/p3)...
    原理：容斥原理
    推导：n个数减去p1,p2,p3...所有倍数，剩下的就是互质数
        p1倍数的个数：n/p1 ; p2倍数的个数：n/p2 ...
        由容斥原理
        φ(n)= n - n/p1 - n/p2 - n/p3 - ...
                + n/p1p2 + n/p2p3 + ...
                - n/p1p2p3 - ...
                + n/p1p2p3p4 + ...
                ...
            = n(1 - n/p1)(1 - n/p2)(1 - n/p3)...

2. (线性)筛法求欧拉函数：求1 ~ n中每个数的欧拉函数

欧拉定理： 若a与n互质， 则 a ^ (φ(n)) ≡ 1 (mod n)

*/

#include <iostream>
#include <algorithm>
using namespace std;


// 1

void euler()
{
    int n;
    cin>>n;
    while (n --)
    {
        int a;
        cin>> a;
        int res = a;
        for(int i = 2; i < a / i; i++)
            if(a % i == 0)
            {
                res = res / i * (i - 1);
                while(a % i == 0)a /= i;
            }
        if(a>1)res = res / a * (a - 1);

        cout << res << endl;
    }
}

// 2 题目：输出1～n中所有数欧拉函数的和

typedef long long LL;
const int N = 1000010;

int phi[N];
int primes[N];
bool st[N];

LL get_eulers(int n)
{
    int cnt = 0;
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] <= n/i; j++)
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0)
            {
                phi[primes[j]*i] = primes[j] * phi[i];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }

    LL res = 0;
    for(int i = 1; i <= n; i++)res += phi[i];
    return res;
}