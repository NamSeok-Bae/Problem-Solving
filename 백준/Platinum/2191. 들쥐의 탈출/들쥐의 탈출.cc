#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, s, v;
bool visit[101];
int c[101];
pair<double, double> mouse[101], cave[101];

bool search(int cur_mouse)
{
	if (visit[cur_mouse])
		return false;
	visit[cur_mouse] = true;
	double mx = mouse[cur_mouse].first;
	double my = mouse[cur_mouse].second;
	for (int i = 1; i <= m; i++)
	{
		double cx = cave[i].first;
		double cy = cave[i].second;
		double distance = (cx - mx) * (cx - mx) + (cy - my) * (cy - my);
		if ((v*s)*(v*s) >= distance)
		{
			if (c[i] == 0 || search(c[i]))
			{
				c[i] = cur_mouse;
				return true;
			}
		}
	}
	return false;
}

int bin_matching()
{
	int ret = n;
	for (int i = 1; i <= n; i++)
	{
		memset(visit, false, sizeof(visit));
		if (search(i))
			ret--;
	}
	return ret;
}

int main()
{
	cin >> n >> m >> s >> v;
	for (int i = 1; i <= n; i++)
	{
		double a, b;
		cin >> a >> b;
		mouse[i] = { a,b };
	}
	for (int i = 1; i <= m; i++)
	{
		double a, b;
		cin >> a >> b;
		cave[i] = { a,b };
	}
	cout << bin_matching();
}