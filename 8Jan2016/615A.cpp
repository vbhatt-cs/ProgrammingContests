#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef unsigned int ul;

const int MD = 1000000007;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<bool> on(m);

    for (int i = 0;i < m;i++)
        on[i] = false;
    
    for (int b = 0;b < n;b++)
    {
        int x;
        scanf("%d", &x);

        while (x--)
        {
            int y;
            scanf("%d", &y);
            on[y - 1] = true;
        }
    }

    for (int i = 0;i < m;i++)
        if (on[i] == false)
        {
            printf("NO");
            return 0;
        }

    printf("YES");
    return 0;
}
