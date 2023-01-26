#include <iostream>
#include <cmath>

using namespace std;

int n,ans;
int col[16];

bool check(int x)
{
    for(int i=0;i<x;i++)
        if(col[x]==col[i] || abs(col[i]-col[x])==x-i)
            return false;
    return true;
}

void nQueen(int x) {
    if(x==n)
    {
        ans++;
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            col[x] = i;
            if(check(x))
                nQueen(x+1);
        }
    }
}

int main()
{
    cin>>n;
    nQueen(0);
    cout<<ans;
}
