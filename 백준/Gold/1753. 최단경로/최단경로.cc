#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int v,e,k,disit[20001];
vector<pair<int,int>> a[20001];
bool visit[20001];

void dijkstra()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,k});
    disit[k] = 0;
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        for(int i=0;i<a[cur].size();i++)
        {
            int next = a[cur][i].first;
            int nextCost = a[cur][i].second;
            if(disit[next] > cost + nextCost)
            {
                disit[next] = cost+ nextCost;
                pq.push({disit[next],next});
            }
        }
    }
}

int main()
{
    cin>>v>>e>>k;
    while(e--)
    {
        int src,dst,weight;
        cin>>src>>dst>>weight;
        a[src].push_back({dst,weight});
    }
    for(int i=1;i<=v;i++)
        disit[i] = 987654321;
    dijkstra();
    for(int i=1;i<=v;i++)
    {
        if(disit[i]==987654321)
            cout<<"INF\n";
        else
            cout<<disit[i]<<"\n";
    }
}
