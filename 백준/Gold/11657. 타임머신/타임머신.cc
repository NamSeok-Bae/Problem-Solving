#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9

int n, m;
int cycle[501];
long long int dist[501];
bool inQ[501];
vector<pair<int, int>> adj[501];
queue<int> q;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	for (int i = 0; i <= n; i++)
		dist[i] = INF;

	dist[1] = 0;
	q.push(1);
	inQ[1] = true;
	cycle[1]++;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		inQ[cur] = false;
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int nxt = adj[cur][i].first;
			int nxtCost = adj[cur][i].second;
			if (dist[nxt] > dist[cur] + nxtCost)
			{
				dist[nxt] = dist[cur] + nxtCost;
				if (!inQ[nxt])
				{
					q.push(nxt);
					inQ[nxt] = true;
					cycle[nxt]++;
					if (cycle[nxt] >= n)
					{
						cout << -1 << "\n";
						return 0;
					}
				}
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (dist[i] == INF)
			cout << -1 << "\n";
		else
			cout << dist[i] << "\n";
	}
}