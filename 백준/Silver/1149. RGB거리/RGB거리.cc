#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1001][1001];
int sum = 1000000;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> dp[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		dp[i + 1][0] = min(dp[i][1] + dp[i + 1][0], dp[i][2] + dp[i + 1][0]);
		dp[i + 1][1] = min(dp[i][0] + dp[i + 1][1], dp[i][2] + dp[i + 1][1]);
		dp[i + 1][2] = min(dp[i][0] + dp[i + 1][2], dp[i][1] + dp[i + 1][2]);
	}
	for (int i = 0; i < 3; i++)
	{
		sum = min(sum, dp[n - 1][i]);
	}
	cout << sum;
}