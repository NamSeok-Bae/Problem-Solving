#include <iostream>
#include <queue>

using namespace std;

int t;
int m;
int a, b;
int map[101][101];
int Bcnt;
bool visit[101];
queue<int> q;

void Bfs(int start)
{
	q.push(start);
	while (!q.empty())
	{
		int check = q.front();
		q.pop();
		if (visit[check] == true)
			continue;
		Bcnt++;
		visit[check] = true;
		for (int i = 1;i <= t;i++)
		{
			if (map[check][i] == 1 & visit[i] == false)
			{
				q.push(i);
			}
		}
	}
}

int main()
{
	cin >> t >> m;
	for (int i = 0;i < m;i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	Bfs(1);
	cout << Bcnt-1;
}