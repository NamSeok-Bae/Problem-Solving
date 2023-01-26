#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,v;
vector<int> vec[1001];
bool visit[1001];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout<<cur<<" ";
        for(int i=0;i<vec[cur].size();i++)
        {
            int next = vec[cur][i];
            if(visit[next]==false)
            {
                q.push(next);
                visit[next] = true;
            }
        }
    }
}
void dfs(int cur)
{
    cout<<cur<<" ";
    for(int i=0;i<vec[cur].size();i++)
    {
        int next = vec[cur][i];
        if(visit[next]==false)
        {
            visit[next] = true;
            dfs(next);
        }
    }
}
int main()
{
    cin>>n>>m>>v;
    for(int i=0;i<m;i++)
    {
        int src,dst;
        cin>>src>>dst;
        vec[src].push_back(dst);
        vec[dst].push_back(src);
    }
    for(int i=1;i<=n;i++)
        sort(vec[i].begin(),vec[i].end());
    
    visit[v] = true;
    dfs(v);
    cout<<endl;
    memset(visit, 0, sizeof(visit));
    bfs(v);
}
