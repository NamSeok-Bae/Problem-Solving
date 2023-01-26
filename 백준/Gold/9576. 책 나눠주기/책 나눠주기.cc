#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int t,n,m,ans;
vector<int> v[1001];
int selected[1001];
bool visit[1001];

bool dfs(int cur)
{
    for(int i=0;i<v[cur].size();i++)
    {
        int next = v[cur][i];
        
        if(visit[next])
            continue;
        
        visit[next] = true;
        if(selected[next]==0 || dfs(selected[next]))
        {
            selected[next] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>t;
    while(t--)
    {
        memset(selected,0,sizeof(selected));
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            v[i].clear();
            int a,b; cin>>a>>b;
            for(int j=a;j<=b;j++)
            {
                v[i].push_back(j);
            }
        }
        for(int i=1;i<=m;i++)
        {
            memset(visit,0,sizeof(visit));
            if(dfs(i))
                ans++;
        }
        cout<<ans<<"\n";
    }
}
