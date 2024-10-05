#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    int tc; cin>>tc;
    for(int t=1;t<=tc;t++) {
        int dist[501];
        int n,m,w;
        vector<pair<pair<int,int>,int>> v;
        
        cin>>n>>m>>w;
        
        for(int j=1;j<=n;j++) {
            dist[j] = INF;
        }
        
        for(int i=0;i<m;i++) {
            int a,b,c; cin>>a>>b>>c;
            v.push_back({{a,b}, c});
            v.push_back({{b,a}, c});
        }
        for(int i=0;i<w;i++) {
            int a,b,c; cin>>a>>b>>c;
            v.push_back({{a,b}, -c});
        }
        
        for(int j=1;j<n;j++) {
            for(int k=0;k<v.size();k++) {
                int from = v[k].first.first;
                int to = v[k].first.second;
                int cost = v[k].second;
                
                if(dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
            }
        }
        bool flag = false;
        for(int j=0;j<v.size();j++) {
            int from = v[j].first.first;
            int to = v[j].first.second;
            int cost = v[j].second;
            
            if(dist[to] > dist[from] + cost) {
                flag = true;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
