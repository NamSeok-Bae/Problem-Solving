#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> v[32001];
int arr[32001];
int result[32001];

void solve()
{

	priority_queue<int,vector<int>,greater<int>> q;
	
	for (int i = 1; i <= n; i++)
		if (arr[i] == 0)
			q.push(i);

	for (int i = 1; i <= n; i++)
	{
		int cur = q.top();
		q.pop();

		result[i] = cur;
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];

			if (--arr[next] == 0)
				q.push(next);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << result[i] << " ";
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}
	solve();
}