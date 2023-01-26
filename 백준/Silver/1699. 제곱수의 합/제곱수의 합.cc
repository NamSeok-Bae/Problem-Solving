#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int cnt;
int dp[100001];
int arr[351];
int m;

int main()
{
	cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		dp[i] = 10000;
	for (int i = 1; i*i <= n; i++)
	{
		dp[i * i] = 1;
		arr[i] = i * i;
		m++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i + arr[j] <= n)
			{
				dp[i + arr[j]] = min(dp[i + arr[j]], dp[i] + 1);
			}
		}
	}
	cout << dp[n];
}