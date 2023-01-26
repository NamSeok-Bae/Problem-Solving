#include <iostream>

using namespace std;

int n,m,dp[1030][1030];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int a; cin>> a;
            dp[i][j] = dp[i][j-1]+dp[i-1][j] -dp[i-1][j-1]+a;
        }
    }
    while(m--)
    {
        pair<int,int> p1,p2;
        cin>>p1.first>>p1.second>>p2.first>>p2.second;
        cout<<dp[p2.first][p2.second]-dp[p1.first-1][p2.second]-dp[p2.first][p1.second-1]+dp[p1.first-1][p1.second-1]<<"\n";
    }
}
