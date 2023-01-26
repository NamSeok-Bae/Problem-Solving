#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define INF 1e9
 
int n, ans, maxflow;
vector<int> v[53];
int capacity[53][53], flow[53][53], prevnode[53];

int my_ctoi(int x)
{
	if (x <= 'Z')
		return x - 'A' + 1;
	else
		return x - 'a' + 27;
}

bool bfs()
{
	memset(prevnode, 0, sizeof(prevnode));
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == 26)
			return true;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			if (prevnode[nxt] == 0 && capacity[cur][nxt] - flow[cur][nxt] > 0)
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
		maxflow = INF;

		for (int i = 26; i != 1; i = prevnode[i])
		{
			maxflow = min(maxflow, capacity[prevnode[i]][i] - flow[prevnode[i]][i]);
		}
		for (int i = 26; i != 1; i = prevnode[i])
		{
			flow[prevnode[i]][i] += maxflow;
			flow[i][prevnode[i]] -= maxflow;
		}

		ans += maxflow;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b;
		int cap;
		cin >> a >> b >> cap;
		int S, E;
		S = my_ctoi(a);
		E = my_ctoi(b);
		v[S].push_back(E);
		v[E].push_back(S);
		capacity[S][E] += cap;
		capacity[E][S] += cap;
	}
	max_flow();
	cout << ans;
}