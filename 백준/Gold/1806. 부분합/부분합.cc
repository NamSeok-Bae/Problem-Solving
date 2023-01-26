#include <iostream>

using namespace std;

int n,s;
int arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    int ans = 987654321;
    for(int i=1;i<=n;i++)
    {
        int l =1 , r=n;
        while(l<=r)
        {
            int mid =(l+r)/2;
            
            if(i + mid > n + 1)
            {
                r = mid -1;
                continue;
            }
            int sum = arr[i+mid-1] - arr[i-1];
            
            if(sum >= s)
            {
                r = mid-1;
                ans = min(ans,mid);
            }
            else
                l = mid +1;
        }
    }
    if(ans == 987654321)
        cout<<0;
    else
        cout<<ans;
}
