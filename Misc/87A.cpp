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
    int a, b;
    scanf("%d %d", &a, &b);

    ll ma = a, mb = b;
	ll sa = 0, sb = 0;

	ll t = 0;
    while (ma != mb)
    {
        if (ma > mb)
        {
            sb += mb - t;
            t = mb;
            mb += b;            
        }
        else
        {
            sa += ma - t;
            t = ma;
            ma += a;
        }
    }

    if (a > b)
        sa += ma - t;
    else
        sb += mb - t;

    if (sa > sb)
        printf("Dasha");
    else if (sb > sa)
        printf("Masha");
    else
        printf("Equal");

    return 0;
}
