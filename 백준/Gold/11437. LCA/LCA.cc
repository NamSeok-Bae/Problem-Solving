#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define K 17

int n, m;
vector<int> v[50001];
int depth[50001];
int dp[50001][K];

void dfs(int x)
{
	for (int i = 0; i < v[x].size(); i++)
	{
		int next = v[x][i];
		if (depth[next] != 0) continue;
		depth[next] = depth[x] + 1;
		dp[next][0] = x;
		dfs(next);
	}
}

void init()
{
	for (int k = 1; k < K; k++)
	{
		for (int i = 1; i < 50001; i++)
		{
			dp[i][k] = dp[dp[i][k - 1]][k - 1];
		}
	}
}

int find(int a, int b)
{
	int x = a, y = b;
	// y가 더 깊은 정점으로 만들기 위함
	if (depth[y] < depth[x]) {
		y = a;
		x = b;
	}

	//높이 맞추기
	for (int i = K - 1; i >= 0; i--)
	{
		//높이의 차가 (1<<i) 보다 크거나 같으면 갱신
		if (depth[y] - depth[x] >= (1 << i))
		{
			y = dp[y][i]; // y는 y의 2^i 번쨰 부모로 갱신
		}
	}
	if (x == y) return x; // 이러면 y가 x의 자식이었던 것이므로 x 출력

	// x랑 y의 최소 공동부모 찾기
	for (int i = K - 1; i >= 0; i--) {
		if (dp[x][i] != dp[y][i]) {
			x = dp[x][i];
			y = dp[y][i];
		}
	}

	return dp[x][0];
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//깊이 초기화
	depth[1] = 1;
	dfs(1);
	//부모자식 초기화
	init();
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << find(a, b) << "\n";
	}
}