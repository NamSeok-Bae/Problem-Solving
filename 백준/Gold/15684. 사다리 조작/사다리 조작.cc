#include <iostream>
#include <algorithm>

using namespace std;

int n,m,h,ans=987654321;
bool check[32][12][12];

bool dfs()
{
    for(int i=1;i<=n;i++)
    {
        int cur = i;
        for(int k=1;k<=h;k++)
        {
            if(check[k][cur][cur+1])
                cur = cur+1;
            else if(check[k][cur-1][cur])
                cur = cur-1;
        }
        if(cur != i)
            return false;
    }
    return true;
}

void np(int idx, int cnt)
{
    if(cnt > 3)
        return;
    
    if(dfs())
    {
        ans = min(ans,cnt);
        return;
    }
    
    for(int i=idx;i<=h;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(check[i][j][j+1] || check[i][j-1][j] || check[i][j+1][j+2])
                continue;
            
            check[i][j][j+1] = true;
            np(i, cnt+1);
            check[i][j][j+1] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m>>h;
    
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        check[a][b][b+1] = true;
    }
    np(1,0);
    if(ans == 987654321)
        cout<<-1;
    else
        cout<<ans;
}
