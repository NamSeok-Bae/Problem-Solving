#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int n;
pair<double,double> arr[101];
priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
bool visit[101];
vector<pair<int,double>> v[101];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double distance = 0;
            distance = sqrt((pow(arr[i].first-arr[j].first,2) + pow(arr[i].second-arr[j].second,2)));
            
            v[i].push_back({j,distance});
            v[j].push_back({i,distance});
        }
    }
    cout<<fixed;
    cout.precision(2);
    double ans = 0;
    for(int i=0;i<v[0].size();i++)
    {
        int next = v[0][i].first;
        double dis = v[0][i].second;
        
        pq.push({dis,next});
    }
    visit[0] = true;
    
    while(!pq.empty())
    {
        double distance = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(visit[cur])
            continue;
        
        visit[cur] = true;
        ans += distance;
        for(int i=0;i<v[cur].size();i++)
        {
            int next = v[cur][i].first;
            double dis = v[cur][i].second;
            
            if(visit[next]==false)
                pq.push({dis, next});
        }
    }
    cout<<ans;
}
