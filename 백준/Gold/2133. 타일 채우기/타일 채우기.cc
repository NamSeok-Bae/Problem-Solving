#include <iostream>

using namespace std;

int n;
int dp[31];
int main()
{
	cin >> n;
	if (n % 2)
	{
		dp[n] = 0;
	}
	else
	{
		dp[2] = 3;
		dp[4] = 11;
		for (int i = 6;i <= n;i += 2)
		{
			dp[i] = dp[i - 2] * 4 - dp[i - 4];
		}
	}
	cout << dp[n];
}