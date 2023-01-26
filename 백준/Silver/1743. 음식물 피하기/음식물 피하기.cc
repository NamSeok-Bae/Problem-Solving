#include <iostream>
#include <queue>

using namespace std;

int n,m,k;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool visit[101][101];
int map[101][101];
int result;

void bfs(int i,int j)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    visit[i][j] = true;
    int cnt = 1;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny = y +dy[i];
            int nx = x +dx[i];
            
            if(ny>=1 && ny<=n && nx>=1 &&nx<=m && visit[ny][nx]==false && map[ny][nx]!=0)
            {
                q.push({ny,nx});
                visit[ny][nx] = true;
                cnt++;
            }
        }
    }
    if(result < cnt)
        result = cnt;
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        map[a][b] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(visit[i][j]==false && map[i][j]==1)
            {
                bfs(i,j);
            }
        }
    }
    cout<<result;
}
