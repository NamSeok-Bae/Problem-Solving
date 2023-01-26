#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        bool check = false;
        int l = 0;
        int r = v.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            
            if(v[m] == a)
            {
                check = true;
                break;
            }
            
            if(v[m] > a)
            {
                r = m -1;
            }
            else
                l = m + 1;
        }
        if(check)
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
    }
}
