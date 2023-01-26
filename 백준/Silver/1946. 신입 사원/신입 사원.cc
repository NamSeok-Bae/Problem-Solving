#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int t,n,result;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        result = 1;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            int a,b; cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        pair<int,int> best = v[0];
        for(int i=1;i<v.size();i++)
        {
            pair<int,int> point = v[i];
            
            if(point.first < best.first || point.second < best.second)
            {
                result++;
                best = point;
            }
        }
        cout<<result<<"\n";
    }
}
