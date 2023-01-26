#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int w,h,arr[51][51];
int dx[8] = {0,0,1,1,1,-1,-1,-1}, dy[8] = {1,-1,0,1,-1,0,1,-1};
bool visit[51][51];

void bfs(int y,int x) {
    queue<pair<int,int>> q;
    q.push({y,x});
    visit[y][x]= true;
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++)
        {
            int ny = y + dy[i];
            int nx = x +dx[i];
            
            if(ny>=0 && ny < h && nx>=0 && nx<w && visit[ny][nx]==false && arr[ny][nx])
            {
                q.push({ny,nx});
                visit[ny][nx] = true;
            }
        }
    }
}

int main()
{
    while(1)
    {
        memset(visit,0,sizeof(visit));
        cin>>w>>h;
        if(w==0 && h==0)
            break;
        
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                cin>>arr[i][j];
            }
        }
        int cnt =0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(arr[i][j]==1 && visit[i][j]==false)
                {
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
}
