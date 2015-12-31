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

int main()
{
    int nA, nB, k, m;
    vector<int> a, b;

    cin >> nA >> nB >> k >> m;
    a.resize(nA);
    b.resize(nB);

    for (int i = 0;i < nA;i++)
        cin >> a[i];

    for (int i = 0;i < nB;i++)
        cin >> b[i];

    if (a[k - 1] < b[nB - m])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

