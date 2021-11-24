#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>

using namespace std;

char a[10];

int main()
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        memset(a, 0, sizeof a);
        int A = 0, B = 0;
        scanf("%s", a);

        if (a[0] == '-')
        {
            cout << "0" << endl;
            continue;
        }

        int l = strlen(a);
        int j = l;
        for (int i = 0; i < 10; i++)
        {
            if (a[i] == '+')
            {
                j = i;
                break;
            }
        }

        for (int i = 0; i < j; i++)
        {
            A += (a[i] - '0') * pow(10, j - 1 - i);
        }
        for (int i = j + 1; i < l; i++)
        {
            B += (a[i] - '0') * pow(10, l - 2 - j);
        }
        cout << A + B * 20 << endl;
    }
    return 0;
}