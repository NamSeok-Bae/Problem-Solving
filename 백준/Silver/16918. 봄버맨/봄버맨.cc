#include <iostream>
#include <queue>

using namespace std;

int r,c,t;
char map[201][201];
int dx[4]={0,1,0,-1},dy[4] = {1,0,-1,0};
queue<pair<int,int>> q;
int cnt=1;

void bfs()
{
    cnt++;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            map[i][j]='O';
        }
    }
    if(cnt==t)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<map[i][j];
            }
            cout<<endl;
        }
        return;
    }
    cnt++;
    while(!q.empty())
    {
        int y = q.front().first;
        int x= q.front().second;
        q.pop();
        
        map[y][x] = '.';
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<c && ny>=0 &&ny<r)
                map[ny][nx]='.';
        }
    }
    if(cnt==t)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<map[i][j];
            }
            cout<<endl;
        }
        return;
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(map[i][j]=='O')
                q.push({i,j});
        }
    }
    bfs();
}

void fill_boom()
{
    
}

int main()
{
    cin>>r>>c>>t;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='O')
            {
                q.push({i,j});
            }
        }
    }
    if(t==1)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<map[i][j];
            }
            cout<<endl;
        }
    }
    else
        bfs();
}
