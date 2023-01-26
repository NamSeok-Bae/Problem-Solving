#include <iostream>

using namespace std;

int n,ans;
int dp[1001][11];

int main()
{
    cin>>n;
    for(int i=0;i<10;i++)
    {
        dp[1][i] = 1;
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(j==0)
                dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%10007;
            }
        }
    }
    for(int i=0;i<=9;i++)
    {
        ans = (ans + dp[n][i])%10007;
    }
    cout<<ans;
}
/*
 0123456789
 
 0123456789
 11 12 13 14 15 16 17 18 19
 22 23 24 25 26 27 28 29
 33 34 35 36 37 38 39
 99
 --55개
 
 111 112 --- 199 45
 222 -- 299 36
 333 -- 399 28
 444 -- 499 21
 555 -- 599 15
 666 -- 699 10
 777 -- 799 6
 888 -- 899 3
 999 1
 -- 165개
 
 1111 1112 --- 1999
 1222 -- 1999
 */
