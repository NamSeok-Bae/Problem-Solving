#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
long long int ans;
long long int map[1001][1001];
int p[1001];
vector < pair<int, pair<int, int>>> v;

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
	cin >> n;
	for (int i = 0; i <= n; i++)
		p[i] = i;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int c;
			cin >> c;
			if(i != j)
				v.push_back({ c,{i,j} });
		}
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
			ans += cur_cost;
		}
	}
	cout << ans;
}