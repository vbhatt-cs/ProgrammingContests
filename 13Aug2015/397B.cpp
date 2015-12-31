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
	ll t, n, l, r;
	cin >> t;
	while (t--)
	{
		cin >> n >> l >> r;
		if (r*(n / l) < n)
			cout << "No\n";
		else
			cout << "Yes\n";

	}
	return 0;
}
