#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int v, e;
int ans;
int p[10001];
vector<pair<int, pair<int,int>>>edge;

int Find(int x)
{
	if (x == p[x])
		return x;
	return p[x] = Find(p[x]);
}

void Union(int a,int b)
{
	if (a != b)
		p[a] = b;
}

int main()
{
	cin >> v >> e;
	for (int i = 1; i <= v; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c,{a,b} });
	}
	sort(edge.begin(), edge.end());
	for (auto i : edge)
	{
		int cur_cost = i.first;
		int v1 = i.second.first;
		int v2 = i.second.second;
		if (Find(v1) != Find(v2))
		{
			Union(Find(v1), Find(v2));
			ans += cur_cost;
		}
	}
	cout << ans;
}