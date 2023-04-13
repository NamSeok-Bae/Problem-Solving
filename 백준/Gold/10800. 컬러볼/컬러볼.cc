#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<pair<int, int>,int> arr[200001];
int color[200001];
int weight[200001];
int dp[200001];

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        int c,w;
        cin>>c>>w;
        arr[i] = {{w, c},i};
    }
    sort(arr, arr + n + 1);
    
    int sum = 0;
    
    for(int i=1;i<=n;i++) {
        int c = arr[i].first.second;
        int w = arr[i].first.first;
        int idx = arr[i].second;
        
        color[c] += w;
        weight[w] += w;
        sum += w;
        
        dp[idx] = sum - color[c] - weight[w] + w;
        
        if(arr[i-1].first.second == c && arr[i-1].first.first == w) {
            dp[idx] = dp[arr[i-1].second];
        }
    }
    
    for(int i=1;i<=n;i++) {
        cout<<dp[i]<<"\n";
    }
}
