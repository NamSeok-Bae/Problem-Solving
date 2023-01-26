#include <iostream>

using namespace std;

int dp[31][2][1001];
int t,w;
int arr[1001];
int result;

int main()
{
    cin>>t>>w;
    for(int i=1;i<=t;i++)
    {
        cin>>arr[i];
        if(arr[i]==1)
            dp[0][0][i] = dp[0][0][i-1]+1;
        else
            dp[0][0][i] = dp[0][0][i-1];
    }
    result = dp[0][0][t];
    for(int i=1;i<=w;i++)
    {
        for(int j=1;j<=t;j++)
        {
            if(i%2)
            {
                if(arr[j]==2)
                    dp[i][1][j] = max(dp[i-1][0][j-1]+1, dp[i][1][j-1]+1);
                else
                    dp[i][1][j] = max(dp[i-1][0][j-1], dp[i][1][j-1]);
            }
            else
            {
                if(arr[j]==1)
                    dp[i][0][j] = max(dp[i-1][1][j-1]+1, dp[i][0][j-1]+1);
                else
                    dp[i][0][j] = max(dp[i-1][1][j-1], dp[i][0][j-1]);
            }
        }
        result = max(result,max(dp[i][0][t],dp[i][1][t]));
    }
    cout<<result;
}
