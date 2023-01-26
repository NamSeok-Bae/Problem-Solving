#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[502][502];
int dp[502][502];
int max_number;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[1][1] = arr[1][1];
	max_number = dp[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
			max_number = max(max_number, dp[i][j]);
		}
	}
	cout << max_number;
}