#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int n, m, d;
int map[20][20];
int new_map[20][20];
bool check[20][20];
int cnt;
vector<int> v;
int max_cnt;
int min_y = 10000;
int min_x = 10000;


void bfs(int dx, int dy)
{
	int x = dx;
	int y = dy;
	int min_num = 10000;
	min_y = 10000;
	min_x = 10000;
	for (int i = 1;i <= y - 1;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (map[i][j] == 1)
			{
				new_map[i][j] = abs(i - y) + abs(j - x);
				if (new_map[i][j] <= d && !check[i][j])
				{
					if (min_num > new_map[i][j])
					{
						min_num = new_map[i][j];
						min_y = i;
						min_x = j;
					}
					else if (min_num == new_map[i][j])
					{
						if (min_x > j)
						{
							min_y = i;
							min_x = j;
						}
					}
				}
			}
		}
	}
}

void combination(int i, int c)
{
	if (c == 3)
	{
		for (int i = n + 1;i > 1;i--)
		{
			int temp = 0;
			vector<int> a;
			vector<int> b;
			for (int j=0;j<v.size();j++)
			{
				bfs(v[j], i);
				if (min_y != 10000)
				{
					a.push_back(min_x);
					b.push_back(min_y);
				}
			}
			for (int j = 0;j < a.size();j++)
			{
				check[b[j]][a[j]] = true;
			}
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				if (check[i][j])
				{
					cnt++;
					check[i][j] = false;
				}
			}
		}
		max_cnt = max(max_cnt, cnt);
		cnt = 0;
		return;
	}
	if (i > m)
		return;
	v.push_back(i);
	combination(i + 1, c + 1);
	v.pop_back();
	combination(i + 1, c);
	return;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	cin >> n >> m >> d;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			cin >> map[i][j];
		}
	}
	combination(1, 0);
	cout << max_cnt;
}