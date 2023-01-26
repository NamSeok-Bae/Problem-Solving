#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
bool visit[1001];
vector<int> v[1001];
int worker[1001];

bool dfs(int cur_worker)
{
	if (visit[cur_worker])
		return false;
	visit[cur_worker] = true;

	for (int i = 0; i < v[cur_worker].size(); i++)
	{
		int work_num = v[cur_worker][i];
		if (worker[work_num] == 0 || dfs(worker[work_num]))
		{
			worker[work_num] = cur_worker;
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