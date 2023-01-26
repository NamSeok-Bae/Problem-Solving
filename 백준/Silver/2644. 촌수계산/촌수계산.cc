#include <iostream>
#include <vector>

using namespace std;

int n;
int a, b;
int m;
int x, y;
int cnt, result;
vector<int> v[101];
bool visit[101];
bool check;

void dfs(int curr)
{
	int start = curr;
	visit[start] = true;
	if (curr == b)
	{
		result = cnt;
		check = true;
		return;
	}
	for (int i = 0; i < v[curr].size(); i++)
	{
		if (visit[v[curr][i]] == false)
		{
			cnt++;
			dfs(v[curr][i]);
			cnt--;
		}	
	}

	return;
}

int main()
{
	cin >> n;
	cin >> a >> b;
	cin >> m;
	while (m--)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(a);
	if (check)
		cout << result << endl;
	else
		cout << -1 << endl;
}