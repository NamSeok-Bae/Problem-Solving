#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
long long ans;

vector<pair<int,int>> pq1;
priority_queue<int,vector<int>,greater<int>> pq2;
priority_queue<int> list;

int main()
{
    cin>>n>>k;
    while(n--)
    {
        int m,v;
        cin>>m>>v;
        pq1.push_back({m,v});
    }
    sort(pq1.begin(),pq1.end());
    while(k--)
    {
        int w; cin>>w;
        pq2.push(w);
    }
    int index = 0;
    while(!pq2.empty())
    {
        int cur_back = pq2.top();
        pq2.pop();
        
        for(;index<pq1.size();index++)
        {
            if(pq1[index].first <= cur_back)
            {
                list.push(pq1[index].second);
            }
            else
                break;
        }
        if(!list.empty())
        {
            ans += list.top();
            list.pop();
        }
    }
    cout<<ans;
}
