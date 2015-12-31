#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef unsigned int ul;

const int MD = 1000000007;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int max = n;
    int min = n / 2 + n%2;

    for (int i = min;i <= max;i++)
    {
        if (i%m == 0)
        {
            printf("%d", i);
            return 0;
        }
    }

    printf("%d", -1);

    return 0;
}
