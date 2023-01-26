#include <iostream>
#include <algorithm>

using namespace std;

int n,m,result,max_value;
int map[501][501];
bool visit[501][501];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void recursion2(int y,int x)
{
    if(y+2 < n && x+1<m)
    {
        max_value = max(max_value, map[y][x] + map[y+1][x]+map[y+2][x]+map[y+1][x+1]);
    }
    if(y+2 < n && x-1>=0)
    {
        max_value = max(max_value, map[y][x] + map[y+1][x]+map[y+2][x]+map[y+1][x-1]);
    }
    if(y-1 >=0 && x+2<m )
    {
        max_value = max(max_value, map[y][x] + map[y][x+1] + map[y-1][x+1] + map[y][x+2]);
    }
    if(y+1 < n && x+2 <m)
    {
        max_value = max(max_value, map[y][x] + map[y][x+1] + map[y+1][x+1] + map[y][x+2]);
    }
}

void recursion(int y,int x,int cnt,int sum)
{
    if(cnt==3)
    {
        max_value = max(max_value,sum);
        return;
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx>=0 && nx<m&&ny>=0 &&ny<n &&visit[ny][nx]==false)
            {
                visit[y][x] = true;
                recursion(ny, nx, cnt+1, sum+map[ny][nx]);
                visit[y][x] = false;
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
            cin>>map[i][j];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            max_value = 0;
            recursion(i, j, 0, map[i][j]);
            recursion2(i, j);
            result = max(result,max_value);
        }
    }
    cout<<result;
}
