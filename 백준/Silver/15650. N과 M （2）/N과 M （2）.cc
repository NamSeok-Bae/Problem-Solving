#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> v;
bool visit[10];

void next_permutation(int depth, int cnt)
{
    if(cnt==m)
    {
        for(auto a:v)
            cout<<a<<" ";
        cout<<endl;
        return;
    }
    else
    {
        for(int i=depth;i<=n;i++)
        {
            if(visit[i])
                continue;;
            
            visit[i] = true;
            v.push_back(i);
            next_permutation(i,cnt+1);
            visit[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    cin>>n>>m;
    next_permutation(1,0);
    
}
