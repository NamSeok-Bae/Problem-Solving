#include <iostream>

using namespace std;

int n,k;
int dp[201][201];

int main()
{
    cin>>n>>k;
    for(int i=0;i<=n;i++)
    {
        dp[1][i] = 1;
        dp[2][i] = i + 1;
    }
    for(int i=3;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int z=0;z<=j;z++)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j-z])%1000000000;
            }
        }
    }
    cout<<dp[k][n];
}
