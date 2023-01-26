#include <iostream>
#include <map>

using namespace std;


map<int,int> m1;
map<int,int> m2;
int n,cnt;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>y>>x;
        m1[x]++;
        m2[y]++;
    }
    
    for(auto a : m1)
    {
        if(a.second >= 2)
            cnt++;
    }
    for(auto a: m2)
    {
        if(a.second>=2)
            cnt++;
    }
    cout<<cnt;
}
