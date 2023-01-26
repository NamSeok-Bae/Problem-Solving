#include <iostream>

using namespace std;

long long dp[91][2];
int n;

int main()
{
	cin >> n;
	dp[1][1] = 1;
	dp[1][0] = 0;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][1] + dp[i - 1][0];
			}
			else {
				dp[i][j] = dp[i - 1][0];
			}
		}
	}
	cout << dp[n][1] + dp[n][0];
}