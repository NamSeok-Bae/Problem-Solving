#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,k,result;
int arr[10001];
vector<int> v[10001];
bool visit[10001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i=0;i<v[cur].size();i++)
        {
            int next = v[cur][i];
            if(visit[next]==false)
            {
                q.push(next);
                visit[next] = true;
            }
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        pq.push({arr[i],i});
    }
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int cost= pq.top().first;
        pq.pop();
        if(visit[cur]==false)
        {
            bfs(cur);
            result += cost;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==false || result > k)
        {
            cout<<"Oh no";
            return 0;
        }
    }
    cout<<result;
}