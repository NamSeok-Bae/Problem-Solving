#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n,arr[10],num[10],ans;

int calculate(int num[])
{
    int temp =0;
    for(int i=0;i<n-1;i++)
    {
        temp += abs(arr[num[i]] - arr[num[i+1]]);
    }
    
    return temp;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        num[i] = i;
    }
    do{
        ans = max(ans,calculate(num));
    }
    while(next_permutation(num, num+n));
    cout<<ans;
}
