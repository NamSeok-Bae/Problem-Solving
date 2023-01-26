#include <iostream>
#include <vector>

using namespace std;

#define K 16

vector<int> v[30001];
int depth[30001];
int dp[30001][K];
int n, m;
int cnt;
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
		for (int i = 1; i < 30001; i++)
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
			cnt += (1 << i);
		}
	}
	if (x == y) return x; // 이러면 y가 x의 자식이었던 것이므로 x 출력

	// x랑 y의 최소 공동부모 찾기
	int ans = 0;
	for (int i = K - 1; i >= 0; i--) {
		if (dp[x][i] != dp[y][i]) {
			x = dp[x][i];
			y = dp[y][i];
			cnt += 2 * (1 << i);
		}
	}
	cnt += 2;
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

	depth[1] = 1;
	dfs(1);
	init();

	cin >> m;
	int start = 1;
	for (int i = 1; i <= m; i++)
	{
		int next;
		cin >> next;
		find(start, next);
		start = next;
	}
	cout << cnt;
}