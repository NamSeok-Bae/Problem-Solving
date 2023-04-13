#include <iostream>

using namespace std;

int t,n;
int sum;
long long dp[1000001];
long long arr[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    
    for (int i=1; i<=1000000;i++) {
        for(int j=1;i*j<=1000000;j++) {
            dp[i*j] += i;
        }
        dp[i] += dp[i-1];
    }
    
    while(t--) {
        cin>>n;
        cout<<dp[n]<<"\n";
    }
}
