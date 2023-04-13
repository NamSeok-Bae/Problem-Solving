#include <iostream>

using namespace std;

int a;
int arr[50001];
int dp[4][50001];
int n;

int main() {
    cin>>a;
    for(int i=1;i<=a;i++) {
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    cin>>n;
    
    for(int i=1;i<=3;i++) {
        for(int j=i*n;j<=a;j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-n] + arr[j] - arr[j-n]);
        }
    }
    cout<<dp[3][a];
}
