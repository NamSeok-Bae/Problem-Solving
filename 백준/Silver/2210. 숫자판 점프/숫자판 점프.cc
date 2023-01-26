#include <iostream>
#include <vector>
#include <string>

using namespace std;

string map[5][5];
bool visit[1000001];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int cnt;

void dfs(int y,int x, string cur)
{
    if(cur.size()==6)
    {
        if(visit[stoi(cur)]==0)
        {
            cnt++;
            visit[stoi(cur)] = 1;
        }
        return;
    }
    
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<5 && ny>=0 &&ny<5)
        {
            dfs(ny, nx, cur+map[ny][nx]);
        }
    }
}

int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>map[i][j];
    
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            dfs(i,j,"");
        }
    }
    cout<<cnt;
}
