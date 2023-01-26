#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>

using namespace std;

int t,n;
string p,x;

deque<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
 
    deque<string> result;
    
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
 
    return result;
}

int main()
{
    cin>>t;
    while(t--)
    {
        bool check = false;
        cin>>p>>n>>x;
        x = x.substr(1,x.size()-2);
        deque<string> v = split(x, ',');
        int cur = 0;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]=='R')
            {
                if(cur)
                    cur = 0;
                else
                    cur = 1;
            }
            else
            {
                if(!v.empty())
                {
                    if(cur)
                        v.pop_back();
                    else
                        v.pop_front();
                }
                else
                {
                    cout<<"error\n";
                    check = true;
                    break;
                }
            }
        }
        if(check)
            continue;
        
        cout<<"[";
        
        if(cur)
        {
            for(int i=v.size()-1;i>=0;i--)
            {
                if(i==0)
                    cout<<v[i];
                else
                    cout<<v[i]<<",";
            }
        }
        else
        {
            for(int i=0;i<v.size();i++)
            {
                if(i==v.size()-1)
                    cout<<v[i];
                else
                    cout<<v[i]<<",";
            }
        }
        cout<<"]\n";
    }
}
