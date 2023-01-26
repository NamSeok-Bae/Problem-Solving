#include <iostream>

using namespace std;

int n, arr[1001],dp[1001],ans;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		dp[i] = arr[i];
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}