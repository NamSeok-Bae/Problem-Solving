#include <iostream>

using namespace std;

int t;
int n;
int dp[11];

int main()
{
	cin >> t;
	dp[1] = 1; // + 1
	dp[2] = 2; // +1+1 , + 2
	dp[3] = 4; // +3, +1+1+1, +2+1, +1+2
	while (t--) {
		cin >> n;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << endl;
	}
}