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

vector<int> tl;
ll ans = 0;
int n=2;

void dfs(vector<vector<int>> &gr, int start)
{
	vector<bool> visitedCur(gr.size());
	for (int c = 0;c < gr.size();c++)
		visitedCur[c] = false;

	ll temp = tl[start] * (gr[start].size() - 1);
	if (temp > ans)
		ans = temp;

	for (int j = 1;j < gr[start].size();j++)
	{
		int curr = gr[start][j] - 1;
		if (curr > start && !visitedCur[curr])
		{
			visitedCur[curr] = true;

			if (n > tl[curr])
				tl[curr] = n;
			temp = tl[curr] * (gr[curr].size() - 1);
			if (temp > ans)
				ans = temp;
			n++;
			dfs(gr, curr);
		}
	}
	n--;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<int>> g(n);

	tl.resize(n);

	for (int i = 0;i < n;i++)
	{
		g[i].push_back(i + 1);
		tl[i] = 1;
	}

	for (int b = 0;b < m;b++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		g[x - 1].push_back(y);
		g[y - 1].push_back(x);
	}

	dfs(g, 0);

	printf("%I64i", ans);

	return 0;
}
