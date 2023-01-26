#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int n,l,r,result;
int map[51][51];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
bool visit[51][51];
bool check = true;
bool play = false;

void bfs(int i,int j)
{
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    q.push({i,j});
    v.push_back({i,j});
    visit[i][j] = true;
    int sum = map[i][j];
    while(!q.empty())
    {
        int y = q.front().first;
        int x= q.front().second;
        int cur = map[y][x];
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int next = map[ny][nx];
            int num = abs(next-cur);
            
            if(ny>=0&&ny<n&&nx>=0&&nx<n&&visit[ny][nx]==false && num>=l&&num<=r)
            {
                q.push({ny,nx});
                v.push_back({ny,nx});
                visit[ny][nx] = true;
                sum+=map[ny][nx];
            }
        }
    }
    if(v.size()>1)
    {
        for(auto a : v)
        {
            map[a.first][a.second] = sum/v.size();
        }
        check = false;
        play = true;
    }
}

int main()
{
    cin>>n>>l>>r;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>map[i][j];
    
    while(1)
    {
        memset(visit,0,sizeof(visit));
        check = true;
        play = false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visit[i][j]==false)
                {
                    bfs(i,j);
                }
            }
        }
        if(play)
            result++;
        if(check)
            break;
    }
    cout<<result;
}
