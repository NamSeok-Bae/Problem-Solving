#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, ans, cnt;
int p[1001];
char sex[1001];
vector < pair<int, pair<int, int>>>v;

int Find(int x)
{
	if (x == p[x])
		return x;
	return p[x] = Find(p[x]);
}

void Union(int a, int b)
{
	if (a != b)
		p[a] = b;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
		cin >> sex[i];
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());

	for (auto i : v)
	{
		int cur_cost = i.first;
		int v1 = i.second.first;
		int v2 = i.second.second;
		if (Find(v1) != Find(v2))
		{
			if (sex[v1] != sex[v2])
			{
				Union(Find(v1), Find(v2));
				ans += cur_cost;
				cnt++;
			}
		}
	}
	if (cnt == n - 1)
		cout << ans;
	else
		cout << -1;
}