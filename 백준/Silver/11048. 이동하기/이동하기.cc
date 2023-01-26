#include <iostream>

using namespace std;

int n,m,arr[1001][1001];
int dp[1001][1001];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1)
            {
                dp[i][j] = dp[i][j-1]+arr[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                dp[i][j] += arr[i][j];
            }
        }
    }
    cout<<dp[n][m];
}
