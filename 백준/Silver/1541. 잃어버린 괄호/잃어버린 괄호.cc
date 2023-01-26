#include <iostream>
#include <string>

using namespace std;

string s;
bool check;
int ans;

int main()
{
    cin>>s;
    string temp;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]=='-'  || s[i]=='+' || i==s.size())
        {
            if(check)
                ans -= stoi(temp);
            else
                ans += stoi(temp);
            
            temp = "";
        }
        else
            temp += s[i];
        
        if(s[i]=='-')
            check= true;
    }
    cout<<ans;
}
