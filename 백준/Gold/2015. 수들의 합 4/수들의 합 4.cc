#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n,k;
int arr[200001];
int dp[200001];
map<long long, long long>m;
long long result;

int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        dp[i] = dp[i-1] + arr[i];
    }
    
    for(int i=1;i<=n;i++) {
        if(dp[i] == k) { result++; }
        result += m[dp[i]-k];
        m[dp[i]]++;
    }
    cout<<result;
}
