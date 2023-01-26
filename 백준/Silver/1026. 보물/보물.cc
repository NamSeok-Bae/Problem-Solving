#include <iostream>
#include <algorithm>

using namespace std;

int n,A[51],B[51],ans;

bool desc(int a,int b)
{
    return a > b;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    
    sort(A,A+n);
    sort(B,B+n,desc);
    for(int i=0;i<n;i++)
    {
        ans += A[i] * B[i];
    }
    cout<<ans;
}
