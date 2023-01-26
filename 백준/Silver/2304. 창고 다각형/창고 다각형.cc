#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,arr[1001];
int maxIdx,maxValue;
int ans;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;
        arr[a] = b;
        
        if(maxValue < b)
        {
            maxValue = b;
            maxIdx = a;
        }
    }
    int leftValue =0;
    int curIdx=0;
    for(int i=0;i<=maxIdx;i++)
    {
        if(leftValue <= arr[i])
        {
            ans += leftValue * (i-curIdx);
            leftValue = arr[i];
            curIdx = i;
        }
    }
    int rightValue =0;
    curIdx = 1000;
    for(int i=1000;i>=maxIdx;i--)
    {
        if(rightValue <= arr[i])
        {
            ans += rightValue * (curIdx - i);
            rightValue = arr[i];
            curIdx = i;
        }
    }
    cout<<ans + maxValue;
}
