#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1e9

int n, p, ans, maxflow;
vector<int> v[401];
int capacity[401][401], prevNode[401], flow[401][401];

bool bfs()
{
	memset(prevNode, 0, sizeof(prevNode));
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == 2)
			return true;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			if (prevNode[nxt] == 0 && capacity[cur][nxt] - flow[cur][nxt] > 0)
			{
				q.push(nxt);
				prevNode[nxt] = cur;
			}
		}
	}
	return false;
}

void max_flow()
{
	while (1)
	{
		if (!bfs())
			break;
		for (int i = 2; i != 1; i = prevNode[i])
		{
			flow[prevNode[i]][i] += 1;
			flow[i][prevNode[i]] -= 1;
		}
		ans += 1;
	}
}

int main()
{
	cin >> n >> p;
	for (int i = 0; i < p; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		capacity[a][b] = 1;
	}
	max_flow();
	cout << ans;
}