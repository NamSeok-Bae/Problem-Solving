#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int ans;
int p[200001];
vector < pair<int, pair<int,int>>> v;

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
	while (1)
	{
		cin >> n >> m;
		if (n ==0 || m==0)
			break;
		for (int i = 0; i <= n; i++)
			p[i] = i;

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			v.push_back({ c,{a,b} });
			ans += c;
		}
		sort(v.begin(), v.end());
		for (auto i : v)
		{
			int cur_cost = i.first;
			int v1 = i.second.first;
			int v2 = i.second.second;
			if (Find(v1) != Find(v2))
			{
				Union(Find(v1), Find(v2));
				ans -= cur_cost;
			}
		}
		cout << ans << "\n";
		ans = 0;
		while (!v.empty())
			v.pop_back();
	}
}