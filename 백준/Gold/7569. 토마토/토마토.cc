#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, h,result;
int map[101][101][101];
bool visit[101][101][101];
queue<pair<int, pair<int,int>>>q;
bool check;
void bfs()
{
	while (!q.empty())
	{
		int z = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		if (x - 1 >= 0)
		{
			if (map[z][y][x - 1] == 0 && visit[z][y][x - 1] == false)
			{
				map[z][y][x - 1] = map[z][y][x] + 1;
				visit[z][y][x - 1] = true;
				q.push(make_pair(z, make_pair(y, x-1)));
			}
		}
		if (x + 1 < m)
		{
			if (map[z][y][x + 1] == 0 && visit[z][y][x + 1] == false)
			{
				map[z][y][x + 1] = map[z][y][x] + 1;
				visit[z][y][x + 1] = true;
				q.push(make_pair(z, make_pair(y, x+1)));
			}
		}
		if (y - 1 >= 0)
		{
			if (map[z][y-1][x] == 0 && visit[z][y-1][x] == false)
			{
				map[z][y-1][x] = map[z][y][x] + 1;
				visit[z][y-1][x] = true;
				q.push(make_pair(z, make_pair(y-1, x)));
			}
		}
		if (y + 1 < n)
		{
			if (map[z][y+1][x] == 0 && visit[z][y+1][x] == false)
			{
				map[z][y+1][x] = map[z][y][x] + 1;
				visit[z][y+1][x] = true;
				q.push(make_pair(z, make_pair(y+1, x)));
			}
		}
		if (z - 1 >= 0)
		{
			if (map[z-1][y][x] == 0 && visit[z-1][y][x] == false)
			{
				map[z-1][y][x] = map[z][y][x] + 1;
				visit[z-1][y][x] = true;
				q.push(make_pair(z-1, make_pair(y, x)));
			}
		}
		if (z + 1 < h)
		{
			if (map[z+1][y][x] == 0 && visit[z+1][y][x] == false)
			{
				map[z+1][y][x] = map[z][y][x] + 1;
				visit[z+1][y][x] = true;
				q.push(make_pair(z+1, make_pair(y, x)));
			}
		}
	}
}

int main()
{
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)//z
	{
		for (int j = 0; j < n; j++)//y
		{
			for (int k = 0; k < m; k++) //x
			{
				cin >> map[i][j][k];
				if (map[i][j][k] == 1)
				{
					q.push(make_pair(i, make_pair(j, k)));
					visit[i][j][k] = true;
				}
			}
		}
	}
	bfs();
	for (int i = 0; i < h; i++)//z
	{
		for (int j = 0; j < n; j++)//y
		{
			for (int k = 0; k < m; k++) //x
			{
				if (map[i][j][k] == 0)
				{
					check = true;
				}
				else
				{
					result = max(result, map[i][j][k]);
				}
			}
		}
	}
	if (check)
		cout << -1;
	else
		cout << result-1;
}