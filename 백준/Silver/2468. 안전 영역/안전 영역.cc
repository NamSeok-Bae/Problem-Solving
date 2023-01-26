#include <iostream>
#include <algorithm>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n,map[101][101],ans = 1;
bool visit[101][101];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

void bfs(int y,int x,int k)
{
    queue<pair<int,int>> q;
    q.push({y,x});
    visit[y][x] = true;
    while(!q.empty())
    {
        int y = q.front().first;
        int x= q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny>=0 && ny<n && nx>=0 && nx<n && visit[ny][nx] == false && map[ny][nx] > k)
            {
                q.push({ny,nx});
                visit[ny][nx] = true;
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }
    
    int k = 1;
    while(1)
    {
        int cnt =0;
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(map[i][j] > k && visit[i][j]==false)
                {
                    bfs(i,j,k);
                    cnt++;
                }
            }
        }
        if(cnt==0)
            break;
        ans = max(ans,cnt);
        k++;
    }
    cout<<ans;
}
