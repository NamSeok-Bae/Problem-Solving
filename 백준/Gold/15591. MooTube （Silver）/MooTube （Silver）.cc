#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n,q;
vector<pair<int,int>> v[5001];
bool visit[5001];

int bfs(int start,int goal)
{
    queue<pair<int,int>> q;
    q.push({start,98754321});
    visit[start] = true;
    int cnt = -1;
    while(!q.empty())
    {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        if(cost >= goal)
            cnt++;
        
        for(int i=0;i<v[cur].size();i++)
        {
            int next = v[cur][i].first;
            int next_cost = v[cur][i].second;
            if(visit[next]==false)
            {
                q.push({next,min(cost,next_cost)});
                visit[next] = true;
            }
        }
    }
    return cnt;
}

int main()
{
    cin>>n>>q;
    for(int i=0;i<n-1;i++)
    {
        int src,dst,cost; cin>>src>>dst>>cost;
        v[src].push_back({dst,cost});
        v[dst].push_back({src,cost});
    }
    for(int i=0;i<q;i++)
    {
        int k,start; cin>>k>>start;
        memset(visit,0,sizeof(visit));
        cout<<bfs(start,k)<<"\n";
    }
}
