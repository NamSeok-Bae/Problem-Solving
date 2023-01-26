#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;;

int n, a, b, d, sum,max_node;
vector<pair<short,short>> v[10001];


void bfs(int start)
{
	bool visit[10001] = { false };
	sum = 0;
	max_node = 0;
	queue<pair<int,int>> q;
	q.push({ start,0 });
	while (!q.empty())
	{
		int cur_node = q.front().first;
		int cur_dist = q.front().second;
		visit[cur_node] = true;
		q.pop();
		if (sum < cur_dist)
		{
			sum = cur_dist;
			max_node = cur_node;
		}

		for (int i = 0; i < v[cur_node].size(); i++)
		{
			int next = v[cur_node][i].first;
			int next_dis = v[cur_node][i].second;

			if (visit[next] == false)
			{
				q.push({ next , cur_dist + next_dis });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

		cin >> n;
		for(int i=0;i<n-1;i++)
		{
			cin >> a >> b >> d;
			v[a].push_back({ b ,d });
			v[b].push_back({a,d});
		}
		bfs(1);
		bfs(max_node);
		cout << sum << "\n";
}