#include <iostream>

using namespace std;

int dp[51][51][51];

int main()
{
	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int A = a, B = b, C = c;
		if (a == -1 && b == -1 && c == -1)
			break;

		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << "\n";
			continue;
		}

		if (a > 20 || b > 20 || c > 20)
			a = b = c = 20;

		for (int i = 0; i <= a; i++)
		{
			for (int j = 0; j <= b; j++)
			{
				for (int k = 0; k <= c; k++)
				{
					if (i == 0 || j == 0 || k == 0)
						dp[i][j][k] = 1;
					else if (i < j && j < k)
						dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
					else
						dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
				}
			}
		}
		cout << "w(" << A<< ", " << B << ", " << C << ") = " << dp[a][b][c] << "\n";
	}
}