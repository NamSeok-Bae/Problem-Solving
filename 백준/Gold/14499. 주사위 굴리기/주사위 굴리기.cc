#include <iostream>

using namespace std;

int n,m,x,y,k;
int map[21][21],cmd;
int dice[7];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int main()
{
    cin>>n>>m>>y>>x>>k;
    
    // 지도 입력
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>map[i][j];
    
    // 명령어 입력
    for(int i=0;i<k;i++)
    {
        cin>>cmd;
        
        int nx = x + dx[cmd-1];
        int ny = y + dy[cmd-1];
        
        if(nx>=0 && nx<m && ny>=0 && ny<n)
        {
            x = nx;
            y = ny;
            int d1 = dice[1], d2 = dice[2], d3= dice[3], d4 = dice[4], d5 = dice[5], d6 = dice[6];
            if(cmd==1)
            {
                dice[1] = d3;
                dice[4] = d1;
                dice[3] = d6;
                dice[6] = d4;
            }
            else if(cmd==2)
            {
                dice[1] = d4;
                dice[4] = d6;
                dice[6] = d3;
                dice[3] = d1;
            }
            else if(cmd==3)
            {
                dice[1] = d2;
                dice[5] = d1;
                dice[2] = d6;
                dice[6] = d5;
            }
            else if(cmd==4)
            {
                dice[1] = d5;
                dice[2] = d1;
                dice[5] = d6;
                dice[6] = d2;
            }
            
            if(map[y][x])
            {
                dice[1] = map[y][x];
                map[y][x] = 0;
            }
            else
                map[y][x] = dice[1];
            cout<<dice[6]<<"\n";
        }
    }
}
