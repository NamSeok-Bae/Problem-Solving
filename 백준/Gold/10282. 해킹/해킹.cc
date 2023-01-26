#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int t,n,d,c;
vector<pair<int,int>> v[10001];
int dist[10001];

void dijkstra()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,c});
    dist[c] = 0;
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for(int i=0;i<v[cur].size();i++)
        {
            int nextCost = v[cur][i].first;
            int next = v[cur][i].second;
            
            if(dist[next] > cost+nextCost)
            {
                dist[next] = cost+nextCost;
                pq.push({dist[next],next});
            }
        }
    }
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>d>>c;
        for(int i=0;i<=n;i++)
        {
            v[i].clear();
            dist[i] = 987654321;
        }
        for(int i=0;i<d;i++)
        {
            int a,b,s; cin>>a>>b>>s;
            v[b].push_back({s,a});
        }
        dijkstra();
        
        int result=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]!=987654321)
            {
                cnt++;
                result = max(result,dist[i]);
            }
        }
        cout<<cnt<<" "<<result<<"\n";
    }
}
