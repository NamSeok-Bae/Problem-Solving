#include <iostream>
#include <queue>

using namespace std;

int n,m,arr[501][501],ans;
int dp[501][501];
int dx[4] = {0,1,0,-1},dy[4]={1,0,-1,0};

void bfs()
{
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({arr[0][0],{0,0}});
    dp[0][0] = 1;
    
    while(!pq.empty())
    {
        int cur = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        for(int i=0;i<4;i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny>=0 && ny<n && nx>=0 && nx<m && cur > arr[ny][nx])
            {
                if(dp[ny][nx])
                {
                    dp[ny][nx] += dp[y][x];
                }
                else
                {
                    dp[ny][nx] = dp[y][x];
                    pq.push({arr[ny][nx],{ny,nx}});
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    
    bfs();
    cout<<dp[n-1][m-1];
}
