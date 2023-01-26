#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,arr[9][9],ans;
vector<pair<int,int>> p;
bool visit_np[9][9];
queue<pair<int,int>> list;

int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

int bfs() {
    queue<pair<int,int>> q = list;
    bool visit[9][9] = {false};
    for(int i=0;i<3;i++)
    {
        arr[p[i].first][p[i].second]= 1;
    }
    
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        visit[y][x] = true;
        
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny>=0 && ny<n && nx>=0 && nx <m && visit[ny][nx]==false && arr[ny][nx]==0)
            {
                q.push({ny,nx});
                visit[ny][nx] = true;
            }
        }
    }
    int cnt =0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0 && visit[i][j]==false)
                cnt++;
        }
    }
    for(int i=0;i<3;i++)
    {
        arr[p[i].first][p[i].second]= 0;
    }
    return cnt;
}

void np()
{
    if(p.size()==3)
    {
        ans = max(ans,bfs());
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==0 && visit_np[i][j]==false)
                {
                    visit_np[i][j] = true;
                    p.push_back({i,j});
                    np();
                    visit_np[i][j] = false;
                    p.pop_back();
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            
            if(arr[i][j]==2)
                list.push({i,j});
        }
    }
    np();
    cout<<ans;
    
}
