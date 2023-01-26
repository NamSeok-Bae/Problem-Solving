#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 1e9

int n, d, k, ans, maxflow;
vector<int> v[302];
int capacity[302][302], prevnode[302], flow[302][302];

bool bfs()
{
	memset(prevnode, -1, sizeof(prevnode));
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == 301)
			return true;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			if (prevnode[nxt] == -1 && capacity[cur][nxt] - flow[cur][nxt] > 0)
			{
				q.push(nxt);
				prevnode[nxt] = cur;
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

		maxflow = MAX;

		for (int i = 301; i != 0; i = prevnode[i])
		{
			maxflow = min(maxflow, capacity[prevnode[i]][i] - flow[prevnode[i]][i]);
		}
		for (int i = 301; i != 0; i = prevnode[i])
		{
			flow[prevnode[i]][i] += maxflow;
			flow[i][prevnode[i]] -= maxflow;
		}

		ans += maxflow;
	}
}

int main()
{
	cin >> n >> k >> d;
	for (int i = 201; i <= 200 + d; i++)
	{
		int cap;
		cin >> cap;
		v[i].push_back(301);
		v[301].push_back(i);
		capacity[i][301] = cap;
	}
	for (int i = 1; i <= n; i++)
	{
		int z;
		cin >> z;
		v[0].push_back(i);
		v[i].push_back(0);
		capacity[0][i] = k;
		for (int j = 1; j <= z; j++)
		{
			int food_num;
			cin >> food_num;
			capacity[i][food_num + 200] = 1;
			v[i].push_back(food_num+200);
			v[food_num + 200].push_back(i);
		}
	}
	max_flow();
	cout << ans;
}