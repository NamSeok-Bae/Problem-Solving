#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long a[4001];
long long b[4001];
long long c[4001];
long long d[4001];
vector<long long>v;
vector<long long>w;
long long result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            v.push_back(a[i] + b[j]);
        }
        for(int j=1;j<=n;j++) {
            w.push_back(c[i] + d[j]);
        }
    }
    
    sort(w.begin(), w.end());
    
    for(auto i : v) {
        auto up = upper_bound(w.begin(), w.end(), -i);
        auto low = lower_bound(w.begin(), w.end(), -i);
        result += up - low;
    }
    cout<<result;
}
