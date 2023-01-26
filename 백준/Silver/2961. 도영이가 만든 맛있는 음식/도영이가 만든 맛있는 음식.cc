#include <iostream>
#include <algorithm>

using namespace std;

int n,s[11],b[11],ans=987654321;

void dfs(int index, int curS, int curB,int size)
{
    if(index==n+1)
    {
        if(size!=0)
            ans = min(ans,abs(curS-curB));
        return;
    }
    
    dfs(index+1,curS*s[index],curB + b[index],size+1);
    dfs(index+1,curS,curB,size);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i]>>b[i];
    
    dfs(1,1,0,0);
    cout<<ans;
}
