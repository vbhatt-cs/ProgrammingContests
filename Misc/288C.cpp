#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned int ul;

const int MD = 1000000007;

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if ((b & 1))
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n;
    scanf("%d", &n);

    int n1 = n, n2 = n;
    int count = 0;
    while (n1)
    {
        count++;
        n1 >>= 1;
    }

    int max = power(2, count) - 1;

    vector<int> a;
    a.resize(n + 1);

    for (int i = 0;i <= n;i++)
        a[i] = i;

    ll beauty = 0;

    while (max)
    {
        int i;
        for (i = 0;i < ((max - ((max + 1) / 2 - 1)) - (max - n2));i++)
        {
            swap(a[n2 - i], a[max - (n2 - i)]);
            beauty += max;
        }
        max = (max + 1) / 2 - 1;
        n2 -= i * 2;
    }

    printf("%I64d\n", beauty * 2);

    for (int i = 0;i <= n;i++)
        printf("%d ", a[i]);

    return 0;
}
