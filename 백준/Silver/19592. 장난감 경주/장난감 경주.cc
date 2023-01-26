#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int t,n,x,y;
vector<double> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y;
        v.clear();
        double min_time = 987654321;
        for(int i=0;i<n;i++)
        {
            double a;
            cin>>a;
            v.push_back(a);
            min_time = min(min_time,x/a);
        }
        if(x/v[n-1] == min_time)
        {
            cout<<0<<"\n";
            continue;
        }
        
        int l = 0;
        int r = 1000000;
        int min_boost = 987654321;
        while(l<=r)
        {
            int m = (l+r)/2;
            
            if(m > y)
            {
                r = m -1;
                continue;
            }
            
            double cnt = 1;
            double distance = x - m;
            
            cnt += distance/v[n-1];
            
            if(cnt < min_time)
            {
                min_boost = min(min_boost,m);
                r = m -1;
            }
            else
                l = m +1;
        }
        if(min_boost==987654321)
            cout<<-1<<"\n";
        else
            cout<<min_boost<<"\n";
    }
}
