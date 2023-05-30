#include <iostream>
#include <string>

using namespace std;

int n;
int map[65][65];

void solve(int x,int y,int k)
{
    int zero = 0;
    for(int i=y;i<y+k;i++)
    {
        for(int j=x; j<x+k;j++)
        {
            if(map[i][j]==0)
                zero++;
        }
    }
    if(zero==k*k)
        cout<<0;
    else if(zero==0)
        cout<<1;
    else
    {
        cout<<"(";
        solve(x,y,k/2);
        solve(x+k/2,y,k/2);
        solve(x,y+k/2,k/2);
        solve(x+k/2,y+k/2,k/2);
        cout<<")";
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
        {
            map[i][j] = s[j]-'0';
        }
    }
    solve(0,0,n);
}
