#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1001],dp[1001],ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i/2; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}