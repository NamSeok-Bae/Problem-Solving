#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1e9

int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit[126][126];
int map[126][126];
int dist[126][126];
int sum;
priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;

void dijkstra()
{
	dist[0][0] = map[0][0];
	pq.push({ dist[0][0],{0,0} });
	while (!pq.empty())
	{
		int x = pq.top().second.second;
		int y = pq.top().second.first;
		int cur_cost = pq.top().first;
		pq.pop();
		if (visit[y][x])
			continue;
		visit[y][x] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || ny >= n || nx < 0 || ny < 0)
				continue;
			if (dist[ny][nx] > cur_cost + map[ny][nx])
			{
				dist[ny][nx] = cur_cost + map[ny][nx];
				pq.push({ dist[ny][nx],{ny,nx} });
			}
		}
	}
}

int main()
{
	int cnt = 0;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		cnt++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				dist[i][j] = MAX;
				visit[i][j] = false;
			}
		}
		dijkstra();
		while (!pq.empty())
			pq.pop();
		cout <<"Problem "<<cnt<<": "<<dist[n - 1][n - 1] << endl;
	}
}