#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n;
int arr[2001],dp[2001];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        dp[i] = 1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j] > arr[i])
            {
                dp[i] = max(dp[i],dp[j] +1);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
        ans = max(ans,dp[i]);
    cout<<n-ans;
}
