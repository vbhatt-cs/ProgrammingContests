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

ll rem(int n)
{
	ll ans = 1;
	int i = n / 9;
	int j = n % 9;
	while (i--)
		ans = ans * 1000000000 % 1000000007;
	while (j--)
		ans *= 10;
	ans %= 1000000007;
	return ans;
}

int main()
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	ll ans = 0;

	int nQ = 0;
	bool greater = false, lesser = false;

	for (int i = 0;i < n;i++)
	{
		if (a[i] == '?')
			nQ++;
		if (b[i] == '?')
			nQ++;
	}

	ll tempL = 1, tempG = 1;
	ll temp1 = 1;

	for (int i = 0;i < n;i++)
	{
		if (a[i] == '?')
		{
			if (b[i] == '?')
				tempL = (tempL * 55) % 1000000007;
			else
				tempL = (tempL * (1 + b[i] - 48)) % 1000000007;
		}
		else if (b[i] == '?')
			tempL = (tempL * (10 - (a[i] - 48))) % 1000000007;
		else
			tempL = (tempL*(a[i] <= b[i] ? 1 : 0)) % 1000000007;
	}

	for (int i = 0;i < n;i++)
	{
		if (a[i] == '?')
		{
			if (b[i] == '?')
				tempG = (tempG * 55) % 1000000007;
			else
				tempG = (tempG * (10 - (b[i] - 48))) % 1000000007;
		}
		else if (b[i] == '?')
			tempG = (tempG * (1 + a[i] - 48)) % 1000000007;
		else
			tempG = (tempG*(a[i] >= b[i] ? 1 : 0)) % 1000000007;
	}

	for (int i = 0;i < n;i++)
	{
		if (a[i] == '?' && b[i] == '?')
			temp1 = (temp1 * 10) % 1000000007;
		else if (isdigit(a[i]) && isdigit(b[i]) && a[i] != b[i])
			temp1 = 0;
	}

	ans = (rem(nQ) - ((tempL + tempG - temp1) % 1000000007)) % 1000000007;
	if (ans < 0)
		ans += 1000000007;

	cout << ans;

	return 0;
}

