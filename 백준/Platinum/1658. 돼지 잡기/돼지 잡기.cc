#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define INF 1e9

int m, n,max_flow,ans;
vector<int> v[1102];
vector<int> key[1102];
int capacity[1102][1102], flow[1102][1102], prevNode[1102];

bool bfs()
{
	memset(prevNode, -1, sizeof(prevNode));
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == 1101)
			return true;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			if (prevNode[nxt] == -1 && capacity[cur][nxt] - flow[cur][nxt] > 0)
			{
				prevNode[nxt] = cur;
				q.push(nxt);
			}
		}
	}
	return false;
}

void maxflow()
{
	while (1)
	{
		if (!bfs())
			break;
		max_flow = INF;

		for (int i = 1101; i != 0; i = prevNode[i])
		{
			max_flow = min(max_flow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);
		}
		for (int i = 1101; i != 0; i = prevNode[i])
		{
			flow[prevNode[i]][i] += max_flow;
			flow[i][prevNode[i]] -= max_flow;
		}
		ans += max_flow;
	}
}

int main()
{
	cin >> m >> n;
	for (int i = 101; i <= m+100; i++)
	{
		int cap;
		cin >> cap;
		capacity[i][1101] = cap;
		v[i].push_back(1101);
		v[1101].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		int z;
		cin >> z;
		for (int j = 1; j <= z; j++)
		{
			int k;
			cin >> k;
			key[k].push_back(i);

			capacity[i][k+100] = INF;
			v[k+100].push_back(i);
			v[i].push_back(k+100);
		}
		int cap;
		cin >> cap;
		capacity[0][i] = cap;

		v[0].push_back(i);
		v[i].push_back(0);
	}
	for (int i = 1; i <= m; i++)
	{
		if (!key[i].size())
			continue;
		for (int j = 0; j < key[i].size(); j++)
		{
			int cur = key[i][j];
			for (int k = j + 1; k < key[i].size(); k++)
			{
				int nxt = key[i][k];

				capacity[nxt][cur] = INF;

				v[cur].push_back(nxt);
				v[nxt].push_back(cur);
			}
		}
	}
	maxflow();
	cout << ans;
}