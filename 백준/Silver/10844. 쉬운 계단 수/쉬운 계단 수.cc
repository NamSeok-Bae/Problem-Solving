#include <iostream>

using namespace std;

int n;
long long int dp[101][10];
long long int sum;
int arr;

int main()
{
	cin >> n;
	dp[1][0] = 0;
	for (int i = 1; i <= 1; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			dp[i][j] = 1;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			}
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		sum += dp[n][i];
	}
	cout << sum % 1000000000;
}