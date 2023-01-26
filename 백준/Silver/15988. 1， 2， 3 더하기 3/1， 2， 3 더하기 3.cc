#include <iostream>

using namespace std;

int n;
long long dp[1000001];

int main()
{
	cin >> n;
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		for (int i = 4; i <= temp; i++)
		{
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])% 1000000009;
		}
		cout << dp[temp] << "\n";
	}
}