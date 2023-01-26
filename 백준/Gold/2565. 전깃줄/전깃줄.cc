#include <iostream>
#include <algorithm>

using namespace std;

int n,dp[501],ans;
pair<int,int>arr[501];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        dp[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[i].second > arr[j].second)
                dp[i] = max(dp[i],dp[j]+1);
        }
        ans = max(ans,dp[i]);
    }
    cout<<n-ans;
}
