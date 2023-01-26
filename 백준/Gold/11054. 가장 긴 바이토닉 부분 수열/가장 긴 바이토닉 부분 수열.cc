#include <iostream>
#include <algorithm>

using namespace std;

int n,arr[1001],dp[1001],dp2[1001],ans;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        dp[i] = 1;
        dp2[i] = 1;
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i] > arr[j])
            {
                dp2[i] = max(dp2[i],dp2[j]+1);
            }
        }
        ans = max(ans,dp2[i]+dp[i]-1);
    }
    cout<<ans;
}
