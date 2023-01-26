#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int n,m,map[101][101];
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
bool visit[101][101];

void bfs()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    visit[0][0] = true;
    while(!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        if(curY == n-1 && curX == m-1 )
        {
            cout<<map[curY][curX];
            return;
        }
        
        for(int i=0;i<4;i++)
        {
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            
            if(ny >=0 && ny<n && nx>=0 && nx<m && visit[ny][nx]==false && map[ny][nx] != 0)
            {
                map[ny][nx] += map[curY][curX];
                visit[ny][nx] = true;
                q.push({ny,nx});
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        for(int j=0;j<s.size();j++)
        {
            map[i][j] = s[j]-'0';
        }
    }
    
    bfs();
}
