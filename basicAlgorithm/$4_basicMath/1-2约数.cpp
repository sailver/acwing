#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

/*

1.试除法求约数
2.约数个数
    题目:给定 n 个正整数 ai，请你输出这些数的乘
        积的约数个数，答案对 10^9+7 取模。
3.约数之和
4.欧几里得算法（辗转相除法）    O(logn)

*/

// 1

vector<int> get_divisors(int n)
{
    vector<int> res;

    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

// 2

typedef long long ll;
const int mod = 1e9 + 7;

void count_divisors(int n)
{
    unordered_map<int, int> primes;
    while (n--)
    {
        int x;
        cin >> x;

        for (int i = 2; i <= x / i; i++) //找到所有质因子
        {
            while (x % i == 0)
            {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1)
            primes[x]++;
    }

    ll res = 1;
    for (auto prime : primes)
        res = res * (prime.second + 1) % mod;

    cout << res << endl;
}

// 3

void add_divisors(int n)
{
    unordered_map<int, int> primes;
    while (n--)
    {
        int x;
        cin >> x;

        for (int i = 2; i <= x / i; i++) //找到所有质因子
        {
            while (x % i == 0)
            {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1)
            primes[x]++;
    }

    ll res = 1;
    for (auto prime : primes)
    {
        int p = prime.first, a = prime.second;
        ll t = 1;
        while (a--)
            t = (t * p + 1) % mod; //多项式加法 --- 秦九韶算法
        res = res * t % mod;
    }

    cout << res << endl;
}

// 4

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}