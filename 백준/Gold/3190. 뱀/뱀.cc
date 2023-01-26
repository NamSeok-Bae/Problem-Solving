#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int n,k,l,t,dir=0; // 0: right, 1:left, 2: up, 3: down
int map[101][101];
bool visit[101][101];
bool game_finish;
list<pair<int,int>> li;
pair<int,char> cmd[101];

int main()
{
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int a,b; cin>>a>>b;
        map[a][b] = 1;
    }
    
    cin>>l;
    int cur_y=1,cur_x=1;
    visit[1][1] = true;
    li.push_back({cur_y,cur_x});
    for(int i=0;i<l;i++)
    {
        cin>>cmd[i].first>>cmd[i].second;
    }
    int index = 0;
    while(1)
    {
        if(t==cmd[index].first)
        {
            switch (dir) {
                case 0:
                    if(cmd[index].second=='D')
                        dir = 3;
                    else
                        dir = 2;
                    break;
                case 1:
                    if(cmd[index].second=='D')
                        dir = 2;
                    else
                        dir = 3;
                    break;
                case 2:
                    if(cmd[index].second=='D')
                        dir = 0;
                    else
                        dir = 1;
                    break;
                case 3:
                    if(cmd[index].second=='D')
                        dir = 1;
                    else
                        dir =0;
                    break;
            }
            index++;
        }
        else
        {
            t++;
            if(dir==0)
            {
                cur_x++;
                if(cur_x > n || visit[cur_y][cur_x])
                {
                    game_finish = true;
                    break;
                }
                else
                {
                    li.push_front({cur_y,cur_x});
                    visit[cur_y][cur_x] = true;
                    if(map[cur_y][cur_x])
                        map[cur_y][cur_x] = 0;
                    else
                    {
                        visit[li.back().first][li.back().second] = false;
                        li.pop_back();
                    }
                }
            }
            else if(dir==1)
            {
                cur_x--;
                if(cur_x < 1 || visit[cur_y][cur_x])
                {
                    game_finish = true;
                    break;
                }
                else
                {
                    li.push_front({cur_y,cur_x});
                    visit[cur_y][cur_x] = true;
                    if(map[cur_y][cur_x])
                        map[cur_y][cur_x] = 0;
                    else
                    {
                        visit[li.back().first][li.back().second] = false;
                        li.pop_back();
                    }
                }
            }
            else if(dir==2)
            {
                cur_y--;
                if(cur_y < 1 || visit[cur_y][cur_x])
                {
                    game_finish = true;
                    break;
                }
                else
                {
                    li.push_front({cur_y,cur_x});
                    visit[cur_y][cur_x] = true;
                    if(map[cur_y][cur_x])
                        map[cur_y][cur_x] = 0;
                    else
                    {
                        visit[li.back().first][li.back().second] = false;
                        li.pop_back();
                    }
                }
            }
            else if(dir==3)
            {
                cur_y++;
                if(cur_y > n || visit[cur_y][cur_x])
                {
                    game_finish = true;
                    break;
                }
                else
                {
                    li.push_front({cur_y,cur_x});
                    visit[cur_y][cur_x] = true;
                    if(map[cur_y][cur_x])
                        map[cur_y][cur_x] = 0;
                    else
                    {
                        visit[li.back().first][li.back().second] = false;
                        li.pop_back();
                    }
                }
            }
        }
    }
    if(game_finish)
    {
        cout<<t;
    }
}
