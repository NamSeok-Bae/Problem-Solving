#include <iostream>

using namespace std;

int map[101][101];
long long dp[101][101];
int n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>map[i][j];
    }
    
    dp[0][0] = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j]==0 || dp[i][j] == 0)
                continue;
            
            if(i+map[i][j] < n)
            {
                dp[i+map[i][j]][j] += dp[i][j];
            }
            if(j+map[i][j]<n)
            {
                dp[i][j+map[i][j]] += dp[i][j];
            }
        }
    }
    cout<<dp[n-1][n-1];
}
