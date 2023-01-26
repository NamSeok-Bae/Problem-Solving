#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s1,s2;
int dp[1001][1001];
stack<char> st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s1>>s2;
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i = s1.size();
    int j = s2.size();
    while(dp[i][j] != 0)
    {
        if(dp[i][j] == dp[i-1][j])
            i--;
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else
        {
            if(dp[i][j]-1==dp[i-1][j-1])
                st.push(s1[i-1]);
            i--;
            j--;
        }
    }
    cout<<dp[s1.size()][s2.size()]<<"\n";
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
