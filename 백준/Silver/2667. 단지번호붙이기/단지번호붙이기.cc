#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;
int map[26][26];
priority_queue<int,vector<int>,greater<int>> ans;
bool visit[26][26];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

int bfs(int y,int x)
{
    queue<pair<int,int>> q;
    q.push({y,x});
    int cnt = 0;
    visit[y][x] = true;
    while(!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        cnt++;
        for(int i=0;i<4;i++)
        {
            int ny = curY+dy[i];
            int nx = curX+dx[i];
            
            if(ny>=0 && ny<n &&nx>=0 && nx<n && map[ny][nx] && visit[ny][nx]==false)
            {
                q.push({ny,nx});
                visit[ny][nx] = true;
            }
        }
    }
    return cnt;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        for(int j=0;j<s.size();j++)
        {
            map[i][j] = s[j]-'0';
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j] && !visit[i][j])
                ans.push(bfs(i,j));
        }
    }
    cout<<ans.size()<<"\n";
    while(!ans.empty())
    {
        cout<<ans.top()<<"\n";
        ans.pop();
    }
}
