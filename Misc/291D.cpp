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
    int n, k;
    scanf("%d %d", &n, &k);

    int done = n - 2;
    int ex = 1;

    for (int i = 0;i < k;i++)
    {
        int j;
        for (j = 0;j < (done - ex);j++)
            printf("%d ", j + 1);
        for (;j < done;j++)
            printf("%d ", j + ex + 1);
        for (;j < n;j++)
            printf("%d ", n);
        done -= ex;
        ex <<= 1;
        printf("\n");
    }

    return 0;
}
