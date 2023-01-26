#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int k, w, h;
int map[201][201];
int arr[201][201];
int dx[8] = { 2,2,1,1,-2,-2,-1,-1 };
int dy[8] = { 1,-1,2,-2,1,-1,2,-2 };
int dx2[4] = { 1,-1,0,0 };
int dy2[4] = { 0,0,1,-1 };
bool visit[201][201][31];

void bfs()
{
	queue<pair<pair<int,int>,int>> q;
	q.push({ {0,0} ,k });
	while (!q.empty())
	{
		int cur_y = q.front().first.first;
		int cur_x = q.front().first.second;
		int cur_k = q.front().second;

		if (cur_y == h - 1 && cur_x == w - 1)
		{
			cout << arr[cur_y][cur_x];
			return;
		}

		q.pop();
		visit[cur_y][cur_x][cur_k] = true;
		for (int i = 0; i < 4; i++)
		{
			int next_y = cur_y + dy2[i];
			int next_x = cur_x + dx2[i];
			if (next_y >= 0 && next_y < h && next_x >= 0 && next_x < w)
			{
				if (map[next_y][next_x] != 1 && visit[next_y][next_x][cur_k]==false)
				{
					q.push({ { next_y , next_x },cur_k });
					arr[next_y][next_x] = arr[cur_y][cur_x] + 1;
					visit[next_y][next_x][cur_k] = true;
				}
			}
		}
		if (cur_k > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int next_y = cur_y + dy[i];
				int next_x = cur_x + dx[i];
				if (next_y >= 0 && next_y < h && next_x >= 0 && next_x < w)
				{
					if (map[next_y][next_x] != 1 && visit[next_y][next_x][cur_k - 1] == false)
					{
						q.push({ { next_y , next_x },cur_k - 1 });
						arr[next_y][next_x] = arr[cur_y][cur_x] + 1;
						visit[next_y][next_x][cur_k-1] = true;
					}
				}
			}
		}
	}
	cout << -1;
}

int main()
{
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
		}
	}
	bfs();
}