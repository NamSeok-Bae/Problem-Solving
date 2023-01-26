#include <iostream>

using namespace std;

int n,k;
int dp[10001];

int main()
{
    cin>> n>>k;
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        int a; cin>>a;
        for(int j=a;j<=k;j++)
        {
            dp[j] += dp[j-a];
        }
    }
    cout<<dp[k];
}
