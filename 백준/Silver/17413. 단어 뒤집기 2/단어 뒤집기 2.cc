#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s,temp;
bool check;

int main()
{
    getline(cin,s);
    for(int i=0;i<=s.size();i++)
    {
        if(i==s.size())
        {
            reverse(temp.begin(),temp.end());
            cout<<temp;
            break;
        }
        
        if(s[i]=='<')
        {
            reverse(temp.begin(),temp.end());
            cout<<temp<<"<";
            temp="";
            check = true;
        }
        else if(s[i]=='>')
        {
            cout<<">";
            check = false;
        }
        else if(check)
            cout<<s[i];
        else
        {
            if(s[i]==' ')
            {
                reverse(temp.begin(),temp.end());
                cout<<temp<<" ";
                temp = "";
            }
            else
                temp += s[i];
        }
    }
}
