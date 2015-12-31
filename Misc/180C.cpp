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
	char a[100001];
	int b[100001];
	scanf("%s", a);

	int count, min = 100001;
	int n = strlen(a);
	for (int i = 0;i < n;i++)
	{
		if (a[i] < 97)
			b[i] = 1;
		else
			b[i] = 0;
	}

	for (int i = 0;i <= n;i++)
	{
		count = 0;
		int j;
		for (j = 0;j < i;j++)
			if (!b[j])
				count++;

		for (;j < n;j++)
			if (b[j])
				count++;

		if (count < min)
			min = count;
	}

	printf("%d", min);

	return 0;
}
