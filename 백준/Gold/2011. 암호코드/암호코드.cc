#include <iostream>
#include <string>

using namespace std;

string s;
int dp[5001];
char c[5001];

int main()
{
    cin>>s;
    for(int i=1;i<=s.size();i++)
    {
        c[i] = s[i-1];
    }
    
    if(s[0] == '0')
    {
        cout<<0;
        return 0;
    }
    
    dp[0] = dp[1] = 1;
    for(int i=2;i<=s.size();i++)
    {
        if(c[i] > '0')
            dp[i] = dp[i-1] % 1000000;
        
        int n = (c[i-1]-'0')*10 + c[i]-'0';
        
        if(10<=n && n<=26)
        {
            dp[i] = (dp[i]+dp[i-2]) % 1000000;
        }
    }
    cout<<dp[s.size()];
}
