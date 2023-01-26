#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> v;

void next_permutation(int depth,int cnt)
{
    if(cnt==m)
    {
        for(auto a: v)
            cout<<a<<" ";
        cout<<"\n";
    }
    else
    {
        for(int i=depth;i<=n;i++)
        {
            v.push_back(i);
            next_permutation(i,cnt+1);
            v.pop_back();
        }
    }
}

int main()
{
    cin>>n>>m;
    next_permutation(1,0);
}
