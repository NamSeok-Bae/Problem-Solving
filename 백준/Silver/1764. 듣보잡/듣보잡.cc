#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n,m;
string s;
map<string,int> ma;
vector<string> v;
int result;

int main()
{
    cin>>n>>m;
    while(n--)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(auto a : v)
        ma[a]++;
    while(m--)
    {
        cin>>s;
        ma[s]++;
        if(ma[s]==2)
            result++;
    }
    cout<<result<<"\n";
    for(auto a : ma)
    {
        if(a.second > 1)
            cout<<a.first<<"\n";
    }
}
