#include <iostream>
#include <vector>

using namespace std;

int n,map[11][11],ans=987654321;
vector<int> v;
bool visit[11];

void np(int cur, int cur_dist)
{
    if(v.size()==n)
    {
        if(map[cur][0]==0)
            return;
        ans = min(ans,cur_dist + map[cur][0]);
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(visit[i])
            continue;
        
        if(map[cur][i]==0)
            continue;
        
        visit[i] = true;
        v.push_back(i);
        np(i,cur_dist + map[cur][i]);
        v.pop_back();
        visit[i] = false;
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>map[i][j];
    
    v.push_back(0);
    visit[0] = true;
    np(0,0);
    cout<<ans;
}
