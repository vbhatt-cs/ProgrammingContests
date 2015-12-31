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
	ll n;
	cin >> n;

	for (ll x = 3;;x *= 3)
	{
		if (n%x != 0)
		{
			cout << (n / x + 1);
			break;
		}
	}
	return 0;
}
