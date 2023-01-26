#include <iostream>

using namespace std;

int n,s,arr[21],ans;

void dfs(int idx, int cur, int size)
{
    if(idx==n)
    {
        if(cur==s && size != 0 )
            ans++;
        return;
    }
    dfs(idx+1,cur+arr[idx],size+1);
    dfs(idx+1,cur,size);
}

int main()
{
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    dfs(0,0,0);
    cout<<ans;
}
