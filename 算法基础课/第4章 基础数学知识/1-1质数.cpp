#include <iostream>
#include <algorithm>
using namespace std;

/*

1. 质数的判定 --- 试除法    O(sqrt(n))
2. 分解质因数 --- 试除法    O(logn) ~ O(sqrt(n))
3. 质数筛
    3.1埃氏筛法   O(nloglogn) 具体请百度  // 1 ~ n 中存在 n/ln(n) 个质数
    3.2线性筛法     利用最小质因子，每个合数只会被删一次


*/

// 1
bool is_prime(int n)
{
    if (n < 2)
        return false;
    /*关于条件语句:
        1. 如果 i<=sqrt(n),sqrt()函数很慢，会降低速度
        2. 如果 i * i <= n, 当n很大时，i*i可能会超限
        故采用 i <= n/i 最好
    */
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
            return false;
    return true;
}

// 2
void divide(int n)
{
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            printf("%d %d\n", i, cnt);
        }
    if (n > 1)
        printf("%d %d\n", n, 1);
}

// 3.1
const int N = 1000010;

bool st_1[N];
int primes_1[N], cnt_1;
void get_primes_1(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st_1[i])
        {
            primes_1[cnt_1++] = i;
            for (int j = i + i; j <= n; j += i)
                st_1[j] = true;
        }
    }
}

// 3.2
bool st_2[N];
int primes_2[N], cnt_2;
void get_primes_2(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st_2[i])primes_2[cnt_2++] = i;
        for(int j = 0; primes_2[j] <= n / i; j++)
        {
            st_2[primes_2[j] * i] = true;
            if(i % primes_2[j] == 0)break;  // primes_2[j] 一定是 i 的最小质因子
        }
    }
}