#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
long long int dp[2][100002];
int arr[2][100002];
long long int mx;
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int a;
				cin >> a;
				arr[i][j] = a;
				dp[i][j] = a;
			}
		}
		for (int j = 0; j + 1 < n; j++)
		{
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
				{
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
					dp[i + 1][j + 2] = max(dp[i + 1][j + 2], dp[i][j] + arr[i + 1][j + 2]);
				}
				else
				{
					dp[i - 1][j + 1] = max(dp[i - 1][j + 1], dp[i][j] + arr[i - 1][j + 1]);
					dp[i - 1][j + 2] = max(dp[i - 1][j + 2], dp[i][j] + arr[i - 1][j + 2]);
				}
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mx = max(mx, dp[i][j]);
			}
		}
		cout<<mx<<endl;
		mx = 0;
	}
}