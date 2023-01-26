#include <iostream>
#include <algorithm>

using namespace std;

int t;
int arr[100002];
int dp[100002];

int main()
{
	int m = -1001;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> arr[i];
	}
	for (int i = 1;i <= t;i++)
	{
		dp[i] = max(arr[i], dp[i-1] + arr[i]);
		if (dp[i] < arr[i])
		{
			dp[i] = 0;
		}
		m = max(m, dp[i]);
	}
	cout << m;
}