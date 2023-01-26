#include <iostream>
#include <queue>

using namespace std;

int n,m,cnt;
int x,y,d; // d = 0 : 북쪽, 1 : 동쪽, 2 : 남쪽, 3 : 서쪽
int map[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs()
{
    queue<pair<int,int>> q;
    q.push({y,x});
    
    while(!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        
        if(map[cur_y][cur_x]==0)
        {
            cnt++;
            map[cur_y][cur_x] = 2;
        }
        
        int rotation_cnt = 0;
        while(1)
        {
            if(rotation_cnt==4)
            {
                if(d==0)
                {
                    if(map[cur_y+1][cur_x]==1)
                        break;
                    else
                        q.push({cur_y+1,cur_x});
                }
                else if(d==1)
                {
                    if(map[cur_y][cur_x-1]==1)
                        break;
                    else
                        q.push({cur_y,cur_x-1});
                }
                else if(d==2)
                {
                    if(map[cur_y-1][cur_x]==1)
                        break;
                    else
                        q.push({cur_y-1,cur_x});
                }
                else
                {
                    if(map[cur_y][cur_x+1]==1)
                        break;
                    else
                        q.push({cur_y,cur_x+1});
                }
                break;
            }
            if(d==0)
            {
                if(map[cur_y][cur_x-1]==0)
                {
                    d = 3;
                    q.push({cur_y,cur_x-1});
                    break;
                }
                else
                    d = 3;
                
            }
            else if(d==1)
            {
                if(map[cur_y-1][cur_x]==0)
                {
                    d = 0;
                    q.push({cur_y-1,cur_x});
                    break;
                }
                else
                    d = 0;
            }
            else if(d==2)
            {
                if(map[cur_y][cur_x+1]==0)
                {
                    d=1;
                    q.push({cur_y,cur_x+1});
                    break;
                }
                else
                    d=1;
            }
            else if(d==3)
            {
                if(map[cur_y+1][cur_x]==0)
                {
                    d = 2;
                    q.push({cur_y+1,cur_x});
                    break;
                }
                else
                    d=2;
            }
            rotation_cnt++;
        }
    }
}

int main()
{
    cin>>n>>m;
    cin>>y>>x>>d;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
        }
    }
    bfs();
    cout<<cnt;
}
