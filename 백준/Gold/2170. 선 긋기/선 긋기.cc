#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin>>tc;
    
    for(int i=0; i<tc;i++) {
        int start, end;
        cin>>start>>end;
        
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());
    
    int ret = 0;
    int start = v[0].first, end = v[0].second;
    
    for (int i = 1; i<v.size(); i++) {
        if (v[i].first >= start && v[i].first <= end) {
            end = max(end, v[i].second);
        } else {
            ret += end - start;
            start = v[i].first;
            end = v[i].second;
        }
    }
    
    ret += end - start;
    cout<<ret;
}