#include <iostream>
#include <algorithm>
#define MAX 1e9
using namespace std;

int n, k;
int temp;
int dp[100001];
int arr[101];

int main()
{
	cin >> n >> k;
	dp[0] = 0;
	for (int i = 1; i <= k; i++)
	{
		dp[i] = MAX;
	}
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
	}
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i+arr[j] <=k)
				dp[i + arr[j]] = min(dp[i+arr[j]],dp[i] + 1);
		}
	}
	if (dp[k] == MAX)
		cout << -1;
	else
		cout<<dp[k];
}