#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n,m,x,ans;
vector<pair<int,int>> v[1001];
int dist[1001][1001];
bool visit[1001];

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    memset(visit,0,sizeof(visit));
    dist[start][start] = 0;
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
            if(dist[start][next] > cost +nextCost)
            {
                dist[start][next] = cost + nextCost;
                pq.push({dist[start][next],next});
            }
        }
    }
}

int main()
{
    cin>>n>>m>>x;
    while(m--)
    {
        int src,dst,w;
        cin>>src>>dst>>w;
        v[src].push_back({dst,w});
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            dist[i][j]=987654321;
        dijkstra(i);
    }
    for(int i=1;i<=n;i++)
    {
        ans = max(ans,dist[i][x] + dist[x][i]);
    }
    cout<<ans;
}
