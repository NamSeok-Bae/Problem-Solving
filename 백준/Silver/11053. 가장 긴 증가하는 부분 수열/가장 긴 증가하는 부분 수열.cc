#include <iostream>
#include <algorithm>
using namespace std;

int t;
int dp[1002];
int arr[1002];
int m;

int main()
{
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> arr[i];
	}
	for (int i = 1;i <= t;i++)
	{
		dp[i] = 1;
		for (int j = 1;j < i;j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		m = max(m, dp[i]);
	}
	cout << m;
}