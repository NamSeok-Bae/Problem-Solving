#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#include <string>
#include <cstring>
#include <set>

using namespace std;

unordered_set<string> se;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        string s; cin>>s;
        se.insert(s);
    }
    for(int i=0;i<M;i++)
    {
        string s; cin>>s;
        string temp;
        for(int j=0;j<s.size();j++)
        {
            
            if(s[j] == ',')
            {
                se.erase(temp);
                temp = "";
            }
            else
                temp += s[j];
        }
        se.erase(temp);
        cout<<se.size()<<"\n";
    }
}
