// 트리는 사이클이 없어야하고 연결되어야함.
// 스패닝트리는 싸이클이 없고 모든 정점이 연결되게 간선을 뽑아쓰는 트리

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, ans;
int p[1001];
vector < pair<int, pair<int, int>>> v;
priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
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
		p[i] = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
		pq.push({ c,{a,b} });
	}
	//sort(v.begin(), v.end());

	//for (auto i : v)
	//{
	//	int cur_cost = i.first;
	//	int v1 = i.second.first;
	//	int v2 = i.second.second;
	//	if (Find(v1) != Find(v2))
	//	{
	//		Union(Find(v1), Find(v2));
	//		ans += cur_cost;
	//	}
	//}
	int cnt = 0;
	while(!pq.empty())
	{
		if (cnt == n - 1)
			break;
		int cur_cost = pq.top().first;
		int v1 = pq.top().second.first;
		int v2 = pq.top().second.second;
		pq.pop();
		if (Find(v1) != Find(v2))
		{
			Union(Find(v1), Find(v2));
			ans += cur_cost;
			cnt++;
		}
	}
	cout << ans;
}