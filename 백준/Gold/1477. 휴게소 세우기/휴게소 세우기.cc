#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,l;
vector<int> v;
int result;

int main() {
    cin>>n>>m>>l;
    for(int i=1;i<=n;i++) {
        int num; cin>>num;
        v.push_back(num);
    }
    v.push_back(0);
    v.push_back(l);
    sort(v.begin(), v.end());
    
    int low = 0, high = l;
    int mid = 0;
    while(low <= high) {
        mid = (low + high)/2;
        
        if(mid == 0) {
            low = mid + 1;
            continue;
        }
        
        int val = 0;
        for(int i=1;i<v.size();i++) {
            val += (v[i] - v[i-1]) / mid;
            
            if((v[i] - v[i-1]) % mid ==0) {
                val--;
            }
        }
        if(val > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
            result = mid;
        }
    }
    cout<<result;
}
