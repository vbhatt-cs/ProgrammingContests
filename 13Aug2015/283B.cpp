#include <iostream>
#include <assert.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

typedef unsigned long ul;
typedef long long int ll;

ll *answerMinus;
ll *answerPlus;
char *reachedPlus;
char *reachedMinus;
ll *a;
int n;

ll fMinus(ll x);

ll fPlus(ll x)
{
    if (reachedPlus[x] == 1)
    {
        answerPlus[x] = -1;
        return answerPlus[x];
    }

    reachedPlus[x] = 1;
    if (x + a[x] <= 0 || x + a[x] > n)
        answerPlus[x] = a[x];
    else if (answerMinus[x + a[x]] == 0)
    {
        ll temp = fMinus(x + a[x]);
        if (temp == -1)
            answerPlus[x] = -1;
        else
            answerPlus[x] = a[x] + temp;
    }
    else if (answerMinus[x + a[x]] == -1)
        answerPlus[x] = -1;
    else
        answerPlus[x] = a[x] + answerMinus[x + a[x]];

    return answerPlus[x];
}

ll fMinus(ll x)
{
    if (reachedMinus[x] == 1)
    {
        answerMinus[x] = -1;
        return answerMinus[x];
    }

    reachedMinus[x] = 1;
    if (x - a[x] <= 0 || x - a[x] > n)
        answerMinus[x] = a[x];
    else if (answerPlus[x - a[x]] == 0)
    {
        ll temp = fPlus(x - a[x]);
        if (temp == -1)
            answerMinus[x] = -1;
        else
            answerMinus[x] = a[x] + temp;
    }
    else if (answerPlus[x - a[x]] == -1)
        answerMinus[x] = -1;
    else
        answerMinus[x] = a[x] + answerPlus[x - a[x]];

    return answerMinus[x];
}

int main()
{
    ll x, y;
    cin >> n;
    a = new ll[n + 1];
    reachedPlus = new char[n + 1];
    reachedMinus = new char[n + 1];
    answerMinus = new ll[n + 1];
    answerPlus = new ll[n + 1];

    for (int i = 0;i <= n;i++)
    {
        reachedPlus[i] = 0;
        reachedMinus[i] = 0;
        answerPlus[i] = 0;
        answerMinus[i] = 0;
    }

    answerPlus[1] = -1;

    for (int i = 2;i <= n;i++)
        cin >> a[i];

    for (int i = 2;i <= n;i++)
    {
        if (answerMinus[i] == 0)
            fMinus(i);
    }

    for (int i = 1;i < n;i++)
    {
        if (answerMinus[i + 1] == -1)
            cout << "-1\n";
        else
            cout << i + answerMinus[i + 1] << endl;
    }

    return 0;
}

