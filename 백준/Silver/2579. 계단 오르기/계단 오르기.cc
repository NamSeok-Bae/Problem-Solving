#include <iostream>
#include <algorithm>

using namespace std;

int dp[302];
int score[302];
int t;

int main()
{
	cin >> t;
	for (int i = 1; i <= t;i++)
	{
		cin >> score[i];
	}
	dp[1] = score[1];
	dp[2] = dp[1] + score[2];
	dp[3] = max(dp[1] + score[3], score[2] + score[3]);
	for (int i = 4;i <= t;i++)
	{
		dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
	}
	cout << dp[t] << endl;
}