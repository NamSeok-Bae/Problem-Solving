#include <iostream>
#include <algorithm>

using namespace std;

int n,dp[1001];
int main()
{
    cin>>n;
    // cout<<(n%2?"SK":"CY"); 솔직히 이것만 써도 정답이 됨.
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    for(int i=4;i<=n;i++)
    {
        dp[i] = min(dp[i-3]+1,dp[i-1]+1);
    }
    cout<<(dp[n]%2?"SK":"CY");
}
