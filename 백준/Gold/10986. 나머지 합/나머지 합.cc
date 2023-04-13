#include <iostream>
#include <map>

using namespace std;

int N,M;
int arr[1000001];
long long dp[1000001];
map<long long, long long> m;
long long result;
int main() {
    cin>> N>> M;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        dp[i] = dp[i-1] + arr[i];
        m[dp[i]%M]++;
    }
    result += m[0];
    
    for(auto &i : m) {
        result += (i.second * (i.second - 1))/2;
    }
    cout<<result;
}
