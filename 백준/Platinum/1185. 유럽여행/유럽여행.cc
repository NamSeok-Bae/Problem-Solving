#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, p, cnt;
int ans = 100000;
int parent[10001];
int cost[10001];
vector<pair<int, pair<int, int>>>v;

int Find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	if (a != b)
		parent[a] = b;
}

int main()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		ans = min(ans, cost[i]);
		parent[i] = i;
	}
	for (int i = 0; i < p; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c*2+cost[a]+cost[b],{a,b} });
	}
	sort(v.begin(), v.end());
	for (auto i : v)
	{
		if (cnt == n - 1)
			break;
		int cur_cost = i.first;
		int v1 = i.second.first;
		int v2 = i.second.second;
		if (Find(v1) != Find(v2))
		{
			Union(Find(v1), Find(v2));
			ans += cur_cost;
			cnt++;
		}
	}
	cout << ans;
}