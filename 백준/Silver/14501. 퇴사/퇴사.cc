#include <iostream>

using namespace std;

int n, ans, temp;
pair<int,int> arr[16];

void dfs(int cur_date, int cur_cost, int next_date)
{
    if(next_date == 0 || cur_date + next_date > n)
    {
        temp = max(temp,cur_cost);
        return;
    }
    for(int i = cur_date + next_date;i<=n;i++)
    {
        dfs(i, cur_cost + arr[cur_date].second , arr[i].first);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i].first>> arr[i].second;
    
    for(int i=0;i<n;i++)
    {
        temp = 0;
        dfs(i,0,arr[i].first);
        ans = max(ans,temp);
    }
    cout<<ans;
}
