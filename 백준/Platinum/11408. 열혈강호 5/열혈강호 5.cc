#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1e9

int n, m;
int total_cnt, total_sal;
int S = 0, T = 801;
vector<pair<int, int>> adj[802];
int capacity[802][802], flow[802][802], prevNode[802];
int cycle[802], dist[802];
bool inQ[802];

void spfa()
{
	memset(prevNode, -1, sizeof(prevNode));
	memset(inQ, false, sizeof(inQ));
	memset(cycle, 0, sizeof(cycle));
	for (int i = 1; i <= T; i++)
		dist[i] = INF;

	dist[S] = 0;
	queue<int> q;
	q.push(S);
	inQ[S] = true;
	cycle[S]++;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		inQ[cur] = false;
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int nxt = adj[cur][i].second;
			int ncst = adj[cur][i].first;

			if (capacity[cur][nxt] > flow[cur][nxt] && dist[nxt] > dist[cur] + ncst)
			{
				dist[nxt] = dist[cur] + ncst;
				prevNode[nxt] = cur;
				if (!inQ[nxt])
				{
					q.push(nxt);
					inQ[nxt] = true;
					cycle[nxt]++;
					if (cycle[nxt] >= n)
						return;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 1; j <= cnt; j++)
		{
			int num, sal;
			cin >> num >> sal;
			adj[i].push_back({ sal,num + 400 });
			adj[num + 400].push_back({ -sal,i });
			capacity[i][num + 400] = 1;
		}
	}
	// Source 와 직원 연결
	for (int i = 1; i <= n; i++)
	{
		adj[S].push_back({ 0,i });
		adj[i].push_back({ 0,S });
		capacity[S][i] = 1;
	}
	// 일과 Sink를 연결
	for (int i = 1; i <= m; i++)
	{
		int w_num = i + 400;
		adj[w_num].push_back({ 0,T });
		adj[T].push_back({ 0,w_num });
		capacity[w_num][T] = 1;
	}
	while (1)
	{
		spfa();
		if (prevNode[T] == -1)
			break;
		int maxflow = INF;
		for (int i = T; i != S; i = prevNode[i])
		{
			maxflow = min(maxflow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);
		}
		for (int i = T; i != S; i = prevNode[i])
		{
			flow[prevNode[i]][i] += maxflow;
			flow[i][prevNode[i]] -= maxflow;
		}
		total_cnt += maxflow;
		total_sal += dist[T];
	}
	cout << total_cnt << "\n" << total_sal << endl;
}