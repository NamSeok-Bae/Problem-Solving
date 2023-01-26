#include <iostream>
#include <vector>

using namespace std;

int n, m;
int cnt;
vector<int> v[1001];
bool visit[1001];

void dfs(int curr)
{
	visit[curr] = true;
	for (int i = 0; i < v[curr].size(); i++)
	{
		if (visit[v[curr][i]] == false)
		{
			dfs(v[curr][i]);
		}
	}
}

int main()
{
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << endl;
}