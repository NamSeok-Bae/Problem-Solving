#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;
string s;
string ans;
vector<char> l,r;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        l.clear();
        r.clear();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='<')
            {
                if(!l.empty())
                {
                    r.push_back(l.back());
                    l.pop_back();
                }
            }
            else if(s[i]=='>')
            {
                if(!r.empty())
                {
                    l.push_back(r.back());
                    r.pop_back();
                }
            }
            else if(s[i]=='-')
            {
                if(!l.empty())
                    l.pop_back();
            }
            else
                l.push_back(s[i]);
        }
        
        for(int i=r.size()-1;i>=0;i--)
            l.push_back(r[i]);
        
        for(auto a : l)
            cout<<a;
        cout<<endl;
    }
}
