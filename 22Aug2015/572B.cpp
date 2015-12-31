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

struct stock
{
    int p, q;
};

bool f(stock &a, stock &b)
{
    return a.p < b.p;
}

int main()
{
    int n, s;
    cin >> n >> s;

    vector<stock> buy, sell;
    buy.resize(n);
    sell.resize(n);

    char temp;

    int i = 0, j = 0;

    while (n--)
    {
        cin >> temp;
        if (temp == 'B')
        {
            cin >> buy[i].p >> buy[i].q;
            i++;
        }
        else
        {
            cin >> sell[j].p >> sell[j].q;
            j++;
        }
    }

    buy.resize(i);
    sell.resize(j);

    sort(buy.begin(), buy.end(), f);
    sort(sell.begin(), sell.end(), f);

    for (int i = 0;i < (int)buy.size() - 1;)
    {
        if (buy[i].p == buy[i + 1].p)
        {
            buy[i].q += buy[i + 1].q;
            buy.erase(buy.begin() + i + 1);
        }
        else
            i++;

    }

    for (int i = 0;i < (int)sell.size() - 1;)
    {
        if (sell[i].p == sell[i + 1].p)
        {
            sell[i].q += sell[i + 1].q;
            sell.erase(sell.begin() + i + 1);
        }
        else
            i++;

    }

    while ((int)buy.size() > s)
        buy.erase(buy.begin());

    while ((int)sell.size() > s)
        sell.pop_back();

    for (int i = sell.size() - 1;i >= 0;i--)
        cout << "S " << sell[i].p << " " << sell[i].q << endl;

    for (int i = buy.size() - 1;i >= 0;i--)
        cout << "B " << buy[i].p << " " << buy[i].q << endl;

    return 0;
}

