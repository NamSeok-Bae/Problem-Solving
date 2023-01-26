#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[102][102];
int min_left=987654321,max_right,min_height=987654321,max_height;
int ans;
bool check[102][102];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;
        ans+=100;
        for(int j=a;j<a+10;j++)
        {
            for(int k=b;k<b+10;k++)
            {
                arr[j][k] += 1;
            }
        }
    }
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        {
            if(arr[i][j] >=2)
            {
                ans -= (arr[i][j]-1);
            }
        }
    }
    cout<<ans;
}
