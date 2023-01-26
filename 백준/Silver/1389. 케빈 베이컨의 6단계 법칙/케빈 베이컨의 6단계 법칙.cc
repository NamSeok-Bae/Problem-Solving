#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v[101];
int dist[101][101];
int result=987654321;
int resultNum;

void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    bool visit[101] = {false};
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
            int next = v[cur][i];
            
            if(dist[start][next] > cost + 1)
            {
                dist[start][next] = cost + 1;
                pq.push({cost+1,next});
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            dist[i][j]=987654321;
        dijkstra(i);
    }
    for(int i=1;i<=n;i++)
    {
        int sum = 0;
        for(int j=1;j<=n;j++)
        {
            sum+=dist[i][j];
        }
        if(result > sum)
        {
            result = sum;
            resultNum = i;
        }
    }
    cout<<resultNum;
}
