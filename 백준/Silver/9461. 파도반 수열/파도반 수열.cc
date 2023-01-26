#include <iostream>

using namespace std;

int t;
int n;
long long dp[101];

int main()
{
	cin >> t;
	dp[1] = 1;
	dp[2] = dp[1];
	dp[3] = dp[2];
	dp[4] = dp[1]+dp[3];
	dp[5] = dp[4];
	dp[6] = dp[5]+dp[3];
	dp[7] = dp[6]+dp[2];
	dp[8] = dp[7]+dp[1];
	for (int i = 0;i < t;i++)
	{
		cin >> n;
		for (int j = 9;j <= n;j++)
		{
			dp[j] = dp[j - 1] + dp[j - 5];
		}
		cout << dp[n] << endl;
	}
}