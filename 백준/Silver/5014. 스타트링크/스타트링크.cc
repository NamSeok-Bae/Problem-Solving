#include <iostream>
#include <queue>

using namespace std;

int f,s,g,u,d;
bool visit[1000001];

void bfs()
{
    queue<pair<int,int>> q;
    q.push({s,0});
    while(!q.empty())
    {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        if(visit[cur])
            continue;
        visit[cur] = true;
        
        if(cur==g)
        {
            cout<<cost;
            return;
        }
        
        int next = cur+u;
        if(next <= f)
            q.push({next,cost+1});
        next = cur - d;
        if(next >=1)
            q.push({next,cost+1});
    }
    cout<<"use the stairs";
}

int main()
{
    cin>>f>>s>>g>>u>>d;
    bfs();
}
