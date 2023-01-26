#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int t,map[51][51],n,m,k,ans;
bool visit[51][51];
int dx[4] = {0,1,0,-1},dy[4]={1,0,-1,0};

void bfs(int y,int x)
{
    queue<pair<int,int>> q;
    q.push({y,x});
    visit[y][x] = true;
    while(!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            
            if(ny>=0 && ny<n && nx>=0 && nx<m && map[ny][nx] && visit[ny][nx] == false)
            {
                q.push({ny,nx});
                visit[ny][nx] = true;
            }
        }
    }
}

int main()
{
    cin>>t;
    while(t--)
    {
        memset(map,0,sizeof(map));
        memset(visit,0,sizeof(visit));
        ans = 0;
        
        cin>>m>>n>>k;
        for(int i=0;i<k;i++)
        {
            int x,y; cin>>x>>y;
            map[y][x] = 1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j] && visit[i][j]==false)
                {
                    ans++;
                    bfs(i,j);
                }
            }
        }
        cout<<ans<<"\n";
    }
}
