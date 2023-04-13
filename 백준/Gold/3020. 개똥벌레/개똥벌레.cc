#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int top[100001];
int bottom[100001];
long long result = 200001, cnt;
int main() {
    cin>>n>>m;
    for(int i=0;i<n/2;i++) {
        cin>>bottom[i]>>top[i];
    }
    
    sort(bottom, bottom + (n/2));
    sort(top, top + (n/2));
    
    for(int i=1;i<=m;i++) {
        
        auto up = upper_bound(top, top + (n/2), m - i) - top;
        auto low = lower_bound(bottom, bottom + (n/2), i) - bottom;
        
        if(result > n - (up + low)) {
            result = n - (up + low);
            cnt = 1;
        } else if(result == n - (up + low)) {
            cnt++;
        }
    }
    cout<<result<<" "<<cnt;
}
