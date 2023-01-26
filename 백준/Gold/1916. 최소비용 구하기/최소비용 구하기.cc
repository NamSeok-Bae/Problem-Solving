#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,dist[1001],visit[1001];
vector<pair<int,int>> v[1001];

void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if(visit[cur])
            continue;
        visit[cur] = true;
        
        for(int i=0;i<v[cur].size();i++)
        {
            int next = v[cur][i].first;
            int nextCost = v[cur][i].second;
            if(dist[next] > cost + nextCost)
            {
                dist[next] = cost + nextCost;
                pq.push({dist[next],next});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int src,dst,w; cin>>src>>dst>>w;
        v[src].push_back({dst,w});
    }
    for(int i=1;i<=n;i++)
        dist[i] = 987654321;
    int start,finish; cin>>start>>finish;
    dijkstra(start);
    cout<<dist[finish];
}
