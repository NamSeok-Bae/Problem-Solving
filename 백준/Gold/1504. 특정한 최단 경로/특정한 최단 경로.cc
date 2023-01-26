#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n,m,dist[801][801];
int ans;
vector<pair<int,int>> v[801];
bool visit[801];

void dijkstra(int start)
{
    memset(visit,0,sizeof(visit));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,start});
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
            if(dist[start][next] > nextCost + cost)
            {
                dist[start][next] = cost + nextCost;
                pq.push({dist[start][next],next});
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int src,dst,w; cin>>src>>dst>>w;
        v[src].push_back({dst,w});
        v[dst].push_back({src,w});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            dist[i][j] = 987654321;
        
        dijkstra(i);
    }
    int start,finish; cin>>start>>finish;
    if(dist[1][start] != 987654321 && dist[start][finish] != 987654321 && dist[finish][n] != 987654321)
    {
        if(dist[1][finish] != 987654321 && dist[finish][start] != 987654321 && dist[start][n] != 987654321)
        {
            ans = min(dist[1][start]+dist[start][finish]+dist[finish][n],dist[1][finish]+dist[finish][start]+dist[start][n]);
        }
        else
            ans = -1;
    }
    else
        ans = -1;
    
    cout<<ans;
}
