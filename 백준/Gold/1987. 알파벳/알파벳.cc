#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
int cnt;
int m;
string s;
char arr[21][21];
bool visit[27];

void dfs(int _x,int _y, int _temp)
{
	int x = _x;
	int y = _y;
	int temp = _temp;

	if (x + 1 < R)
	{
		if (visit[arr[x + 1][y] - 'A'] == false)
		{
			visit[arr[x+1][y] - 'A'] = true;
			dfs(x + 1, y, temp + 1);
			visit[arr[x + 1][y] - 'A'] = false;
		}
	}
	if (y + 1 < C)
	{
		if (visit[arr[x][y + 1] - 'A'] == false)
		{
			visit[arr[x][y+1] - 'A'] = true;
			dfs(x, y + 1, temp + 1);
			visit[arr[x][y + 1] - 'A'] = false;
		}
	}
	if (x - 1 >= 0)
	{
		if (visit[arr[x - 1][y] - 'A'] == false)
		{
			visit[arr[x-1][y] - 'A'] = true;
			dfs(x - 1, y, temp + 1);
			visit[arr[x - 1][y] - 'A'] = false;
		}
	}
	if (y - 1 >= 0)
	{
		if (visit[arr[x][y - 1] - 'A'] == false)
		{
			visit[arr[x][y-1] - 'A'] = true;
			dfs(x, y - 1, temp + 1);
			visit[arr[x][y - 1] - 'A'] = false;
		}
	}
	if (m < temp)
		m = temp;
	return;
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char a;
			cin >> a;
			arr[i][j] = a;
		}
	}
	visit[arr[0][0] - 'A'] = true;
	dfs(0, 0,1);
	cout << m;
}