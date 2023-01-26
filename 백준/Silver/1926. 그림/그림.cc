#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int dx[4] = {0,1,0,-1},dy[4]={1,0,-1,0};
int map[501][501];
bool visit[501][501];
int cnt,result;

void bfs(int i,int j)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    visit[i][j] = true;
    int bfsCnt = 1;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny>=0 && ny<n&&nx>=0 &&nx<m&&map[ny][nx] && visit[ny][nx]==false)
            {
                q.push({ny,nx});
                visit[ny][nx] = true;
                bfsCnt++;
            }
        }
    }
    cnt++;
    result = max(result,bfsCnt);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j] && visit[i][j]==false)
                bfs(i,j);
        }
    }
    cout<<cnt<<"\n"<<result;
}