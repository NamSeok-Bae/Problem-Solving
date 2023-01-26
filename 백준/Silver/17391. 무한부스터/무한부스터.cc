#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int map[301][301];
int N, M, cnt, ans;
queue < pair<int, pair<int, int>> > q;
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
bool visited[301][301];
void bfs(int x, int y)
{
	while (!q.empty())
	{
		int curx = q.front().second.first;
		int cury = q.front().second.second;
		int cnt = q.front().first;
		q.pop();
		int boost = map[cury][curx];

		if (curx == M && cury == N)
		{
			ans = cnt;
			break;
		}

		for (int i = 0; i < 2; i++)
		{
			int nx, ny;
			
			for (int j = 1; j <= boost; j++)
			{
				nx = curx + dx[i] * j;
				ny = cury + dy[i] * j;

				if (nx >= 1 && nx <= M && ny >= 1 && ny <= N)
				{
					if (visited[ny][nx])
						continue;
					visited[ny][nx] = true;
					q.push({ cnt + 1, {nx, ny} });
				}
			}
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];

	q.push({ 0, {1 , 1} });
	bfs(1, 1);
	cout << ans << '\n';
	return 0;
}