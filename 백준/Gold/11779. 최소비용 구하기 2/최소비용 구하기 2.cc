#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int cost[1001];
int cnt[1001];
int before[1001];

vector<pair<int,int>> v[1001];

int main() {
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<=n;i++) {
        cost[i] = 987654321;
    }
    
    for(int i=0;i<m;i++) {
        int a,b,c; cin>>a>>b>>c;
        
        v[a].push_back({b,c});
    }
    
    int start,goal; cin>>start>>goal;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0, start});
    cost[start] = 0;
    
    while(!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(cost[cur] < cur_cost) continue;
        
        for(int i=0;i<v[cur].size();i++) {
            int next = v[cur][i].first;
            int next_cost = v[cur][i].second;
            
            if(cost[next] > cur_cost + next_cost) {
                cost[next] = cur_cost + next_cost;
                cnt[next] = cnt[cur] + 1;
                before[next] = cur;
                pq.push({cur_cost + next_cost, next});
            }
        }
    }
    
    cout<<cost[goal]<<"\n"<<cnt[goal] + 1 << "\n";
    
    vector<int> temp;
    int cur = goal;
    while(true) {
        temp.push_back(cur);
        if(before[cur] == 0) break;
        cur = before[cur];
    }
    for(int i=temp.size()-1;i>=0;i--) {
        cout<<temp[i]<<" ";
    }
}
