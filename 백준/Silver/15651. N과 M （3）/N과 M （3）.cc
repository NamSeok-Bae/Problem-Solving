#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> v;
bool visit[10];

void next_permutation(int cnt)
{
    if(cnt==m)
    {
        for(auto a:v)
            cout<<a<<" ";
        cout<<"\n";
        return;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(visit[i])
                continue;
            
            v.push_back(i);
            next_permutation(cnt+1);
            v.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    next_permutation(0);
}
