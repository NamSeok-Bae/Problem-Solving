#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int dp[100001];

int result;

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        dp[i] += dp[i-1] + arr[i];
    }
    
    for(int i=2;i<n;i++) {
        result = max(result, dp[i] - dp[1] + dp[n-1] - dp[i-1]);
    }
    
    for(int i=2;i<n;i++) {
        result = max(result, dp[n] - dp[1] + dp[n] - dp[i] - arr[i]);
    }
    
    for (int i=n-1;i>1;i--) {
        result = max(result, dp[n-1] + dp[i-1] - arr[i]);
    }

    cout<<result;
}
