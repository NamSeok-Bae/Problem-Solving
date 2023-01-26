#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
bool visit[201];
int cow[201];
vector<int> v[201];

bool dfs(int cur_cow)
{
	if (visit[cur_cow])
		return false;
	visit[cur_cow] = true;

	for (int i = 0; i < v[cur_cow].size(); i++)
	{
		int cow_num = v[cur_cow][i];
		if (cow[cow_num] == 0 || dfs(cow[cow_num]))
		{
			cow[cow_num] = cur_cow;
			return true;
		}
	}
	return false;
}

int bin_matching()
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(visit, false, sizeof(visit));
		if (dfs(i))
			ret++;
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int s;
		cin >> s;
		for (int j = 0; j < s; j++)
		{
			int a;
			cin >> a;
			v[i].push_back(a);
		}
	}
	cout << bin_matching();
}