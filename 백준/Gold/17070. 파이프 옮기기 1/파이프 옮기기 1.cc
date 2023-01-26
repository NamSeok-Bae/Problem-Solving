#include <iostream>
#include <algorithm>

using namespace std;

int n,map[17][17],ans;

void dfs(int y,int x,int cur)
{
    if(y==n-1 && x==n-1)
    {
        ans++;
        return;
    }
    
    switch (cur) {
        case 0:
            if(map[y][x+1]==0 && x+1<n)
            {
                dfs(y, x+1,0);
                if(map[y+1][x+1]==0 && map[y+1][x]==0 && y+1<n)
                    dfs(y+1,x+1,1);
            }
            break;
        case 1:
            if(map[y][x+1]==0 && x+1 < n)
                dfs(y, x+1,0);
            if(map[y+1][x]==0 && y+1 < n)
            {
                dfs(y+1,x,2);
                if(map[y][x+1]==0 && map[y+1][x+1]==0 && x+1 < n)
                    dfs(y+1,x+1,1);
            }
            break;
        case 2:
            if(map[y+1][x]==0 && y+1<n)
            {
                dfs(y+1,x,2);
                if(map[y+1][x+1]==0 && map[y][x+1]==0 && x+1<n)
                    dfs(y+1,x+1,1);
            }
            break;
    }
    
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>map[i][j];
    
    if(map[0][0]==1 || map[0][1]==1)
        cout<<0;
    else
    {
        dfs(0,1,0);
        cout<<ans;
    }
}
